#include "venetian_blinds.h"

#include <algorithm>
#include <cmath>

#include "esphome/core/hal.h"
#include "esphome/core/log.h"

namespace esphome::venetian_blinds {

static const char *const TAG = "venetian_blinds.cover";
static constexpr float EPSILON = 0.0001f;

using namespace esphome::cover;

void VenetianBlinds::setup() {
  const uint32_t overhead =
      this->tilt_duration_ + this->actuator_activation_duration_;
  this->open_position_duration_ = this->open_duration_ - overhead;
  this->close_position_duration_ = this->close_duration_ - overhead;

  auto restore = this->restore_state_();
  if (restore.has_value()) {
    restore->apply(this);
  } else {
    this->position = COVER_CLOSED;
    this->tilt = COVER_CLOSED;
    this->publish_state();
  }

  this->target_position_ = this->position;
  this->target_tilt_ = this->tilt;
}

void VenetianBlinds::dump_config() {
  LOG_COVER("", "Venetian Blind", this);
  ESP_LOGCONFIG(TAG, "  Open duration: %.1fs", this->open_duration_ / 1000.0f);
  ESP_LOGCONFIG(TAG, "  Close duration: %.1fs", this->close_duration_ / 1000.0f);
  ESP_LOGCONFIG(TAG, "  Tilt duration: %.1fs", this->tilt_duration_ / 1000.0f);
  ESP_LOGCONFIG(TAG, "  Actuator activation: %.1fs",
                this->actuator_activation_duration_ / 1000.0f);
}

CoverTraits VenetianBlinds::get_traits() {
  auto traits = CoverTraits();
  traits.set_supports_position(true);
  traits.set_supports_tilt(true);
  traits.set_supports_stop(true);
  traits.set_supports_toggle(true);
  traits.set_is_assumed_state(this->assumed_state_);
  return traits;
}

void VenetianBlinds::control(const CoverCall &call) {
  if (call.get_stop()) {
    this->start_direction_(COVER_OPERATION_IDLE);
    this->publish_state();
    return;
  }

  if (call.get_toggle().has_value()) {
    if (this->current_operation != COVER_OPERATION_IDLE) {
      this->start_direction_(COVER_OPERATION_IDLE);
      this->publish_state();
      return;
    }

    const bool open_next =
        this->position <= EPSILON ||
        this->last_operation_ == COVER_OPERATION_CLOSING;
    this->target_position_ = open_next ? COVER_OPEN : COVER_CLOSED;
    this->target_tilt_ = open_next ? COVER_OPEN : COVER_CLOSED;
    this->start_direction_(open_next ? COVER_OPERATION_OPENING
                                     : COVER_OPERATION_CLOSING);
    return;
  }

  if (call.get_position().has_value()) {
    const float requested = *call.get_position();
    if (requested > this->position + EPSILON ||
        (requested >= COVER_OPEN - EPSILON &&
         this->tilt < COVER_OPEN - EPSILON)) {
      this->target_position_ = requested;
      this->target_tilt_ = COVER_OPEN;
      this->start_direction_(COVER_OPERATION_OPENING);
    } else if (requested < this->position - EPSILON ||
               (requested <= EPSILON && this->tilt > EPSILON)) {
      this->target_position_ = requested;
      this->target_tilt_ = COVER_CLOSED;
      this->start_direction_(COVER_OPERATION_CLOSING);
    }
    return;
  }

  if (call.get_tilt().has_value()) {
    const float requested = *call.get_tilt();
    if (requested > this->tilt + EPSILON) {
      this->target_position_ = this->position;
      this->target_tilt_ = requested;
      this->start_direction_(COVER_OPERATION_OPENING);
    } else if (requested < this->tilt - EPSILON) {
      this->target_position_ = this->position;
      this->target_tilt_ = requested;
      this->start_direction_(COVER_OPERATION_CLOSING);
    }
  }
}

void VenetianBlinds::loop() {
  if (this->current_operation == COVER_OPERATION_IDLE)
    return;

  const uint32_t now = millis();
  this->recompute_state_();

  if (this->is_at_target_()) {
    this->position = this->target_position_;
    this->tilt = this->target_tilt_;
    this->start_direction_(COVER_OPERATION_IDLE);
    this->publish_state();
    return;
  }

  if (now - this->last_publish_time_ >= 1000) {
    this->publish_state(false);
    this->last_publish_time_ = now;
  }
}

void VenetianBlinds::stop_previous_trigger_() {
  if (this->previous_trigger_ != nullptr) {
    this->previous_trigger_->stop_action();
    this->previous_trigger_ = nullptr;
  }
}

void VenetianBlinds::start_direction_(CoverOperation direction) {
  if (direction == this->current_operation &&
      direction != COVER_OPERATION_IDLE)
    return;

  this->recompute_state_();

  Trigger<> *trigger = nullptr;
  switch (direction) {
    case COVER_OPERATION_OPENING:
      this->last_operation_ = direction;
      trigger = &this->open_trigger_;
      break;
    case COVER_OPERATION_CLOSING:
      this->last_operation_ = direction;
      trigger = &this->close_trigger_;
      break;
    case COVER_OPERATION_IDLE:
      trigger = &this->stop_trigger_;
      break;
    default:
      return;
  }

  this->current_operation = direction;
  const uint32_t now = millis();
  this->last_recompute_time_ = now;
  this->activation_until_ =
      direction == COVER_OPERATION_IDLE
          ? now
          : now + this->actuator_activation_duration_;

  this->stop_previous_trigger_();
  trigger->trigger();
  this->previous_trigger_ = trigger;
}

void VenetianBlinds::recompute_state_() {
  if (this->current_operation == COVER_OPERATION_IDLE)
    return;

  const uint32_t now = millis();
  if (now <= this->activation_until_)
    return;

  const uint32_t movement_start =
      std::max(this->last_recompute_time_, this->activation_until_);
  float remaining_ms = static_cast<float>(now - movement_start);
  this->last_recompute_time_ = now;

  if (this->current_operation == COVER_OPERATION_OPENING) {
    if (this->tilt < this->target_tilt_ && remaining_ms > 0.0f) {
      const float needed_ms =
          (this->target_tilt_ - this->tilt) * this->tilt_duration_;
      const float used_ms = std::min(remaining_ms, needed_ms);
      this->tilt += used_ms / this->tilt_duration_;
      remaining_ms -= used_ms;
    }
    if (remaining_ms > 0.0f && this->position < this->target_position_) {
      this->position += remaining_ms / this->open_position_duration_;
    }
  } else if (this->current_operation == COVER_OPERATION_CLOSING) {
    if (this->tilt > this->target_tilt_ && remaining_ms > 0.0f) {
      const float needed_ms =
          (this->tilt - this->target_tilt_) * this->tilt_duration_;
      const float used_ms = std::min(remaining_ms, needed_ms);
      this->tilt -= used_ms / this->tilt_duration_;
      remaining_ms -= used_ms;
    }
    if (remaining_ms > 0.0f && this->position > this->target_position_) {
      this->position -= remaining_ms / this->close_position_duration_;
    }
  }

  this->position = std::clamp(this->position, 0.0f, 1.0f);
  this->tilt = std::clamp(this->tilt, 0.0f, 1.0f);
}

bool VenetianBlinds::is_at_target_() const {
  if (this->current_operation == COVER_OPERATION_OPENING) {
    return this->position >= this->target_position_ - EPSILON &&
           this->tilt >= this->target_tilt_ - EPSILON;
  }
  if (this->current_operation == COVER_OPERATION_CLOSING) {
    return this->position <= this->target_position_ + EPSILON &&
           this->tilt <= this->target_tilt_ + EPSILON;
  }
  return true;
}

}  // namespace esphome::venetian_blinds
