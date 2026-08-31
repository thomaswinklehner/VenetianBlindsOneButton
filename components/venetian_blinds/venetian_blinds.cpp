#include "venetian_blinds.h"

#include "esphome/core/hal.h"
#include "esphome/core/log.h"

#include <algorithm>
#include <cmath>

namespace esphome::venetian_blinds {

static const char *const TAG = "venetian_blinds.cover";

using namespace esphome::cover;

void VenetianBlinds::dump_config() {
  LOG_COVER("", "Venetian Blinds", this);
  ESP_LOGCONFIG(TAG, "  Open Duration: %.1fs", this->open_duration_ / 1e3f);
  ESP_LOGCONFIG(TAG, "  Close Duration: %.1fs", this->close_duration_ / 1e3f);
  ESP_LOGCONFIG(TAG, "  Tilt Duration: %.1fs", this->tilt_duration_ / 1e3f);
  ESP_LOGCONFIG(TAG, "  Actuator Activation Duration: %.1fs",
                this->actuator_activation_duration_ / 1e3f);
}

void VenetianBlinds::setup() {
  if (this->open_duration_ < this->tilt_duration_ ||
      this->close_duration_ < this->tilt_duration_) {
    ESP_LOGE(TAG, "'%s': open/close duration must be >= tilt duration",
             this->name_.c_str());
    this->mark_failed();
    return;
  }

  auto restore = this->restore_state_();
  if (restore.has_value()) {
    restore->apply(this);
  } else {
    this->position = COVER_CLOSED;
    this->tilt = COVER_CLOSED;
  }

  const uint32_t tilt_and_activation =
      this->tilt_duration_ + this->actuator_activation_duration_;

  if (this->open_duration_ < tilt_and_activation ||
      this->close_duration_ < tilt_and_activation) {
    ESP_LOGE(TAG, "'%s': open/close duration must be >= tilt + actuator duration",
             this->name_.c_str());
    this->mark_failed();
    return;
  }

  this->open_net_duration_ = this->open_duration_ - tilt_and_activation;
  this->close_net_duration_ = this->close_duration_ - tilt_and_activation;

  this->exact_position_ =
      static_cast<int32_t>(this->close_net_duration_ * this->position);
  this->exact_tilt_ =
      static_cast<int32_t>(this->tilt_duration_ * this->tilt);
}

CoverTraits VenetianBlinds::get_traits() {
  auto traits = CoverTraits();
  traits.set_supports_position(true);
  traits.set_supports_tilt(true);
  traits.set_supports_stop(true);
  traits.set_is_assumed_state(this->assumed_state_);
  return traits;
}

void VenetianBlinds::control(const CoverCall &call) {
  if (call.get_stop()) {
    this->start_direction_(COVER_OPERATION_IDLE);
    this->publish_state();
    return;
  }

  if (call.get_position().has_value()) {
    const float requested_position =
        std::clamp(*call.get_position(), 0.0f, 1.0f);

    if (std::fabs(requested_position - this->position) < 0.001f &&
        !(requested_position == COVER_CLOSED && this->tilt > 0.001f)) {
      return;
    }

    CoverOperation operation;
    uint32_t operation_duration;

    if (requested_position < this->position ||
        requested_position == COVER_CLOSED) {
      operation = COVER_OPERATION_CLOSING;
      operation_duration = this->close_net_duration_;
      this->target_tilt_ = 0;
    } else {
      operation = COVER_OPERATION_OPENING;
      operation_duration = this->open_net_duration_;
      this->target_tilt_ = this->tilt_duration_;
    }

    this->target_position_ =
        static_cast<uint32_t>(requested_position * operation_duration);
    this->start_direction_(operation);
  }

  if (call.get_tilt().has_value()) {
    const float requested_tilt = std::clamp(*call.get_tilt(), 0.0f, 1.0f);

    if (std::fabs(requested_tilt - this->tilt) < 0.001f)
      return;

    const auto operation =
        requested_tilt < this->tilt ? COVER_OPERATION_CLOSING
                                    : COVER_OPERATION_OPENING;

    this->target_position_ = static_cast<uint32_t>(this->exact_position_);
    this->target_tilt_ =
        static_cast<uint32_t>(requested_tilt * this->tilt_duration_);

    this->start_direction_(operation);
  }
}

void VenetianBlinds::loop() {
  if (this->current_operation == COVER_OPERATION_IDLE)
    return;

  const uint32_t now = millis();

  this->recompute_position_();

  if (this->is_at_target_()) {
    this->start_direction_(COVER_OPERATION_IDLE);
    this->publish_state();
    return;
  }

  if (now - this->last_publish_time_ > 1000) {
    this->publish_state(false);
    this->last_publish_time_ = now;
  }
}

void VenetianBlinds::stop_prev_trigger_() {
  if (this->prev_command_trigger_ != nullptr) {
    this->prev_command_trigger_->stop_action();
    this->prev_command_trigger_ = nullptr;
  }
}

bool VenetianBlinds::is_at_target_() const {
  switch (this->current_operation) {
    case COVER_OPERATION_OPENING:
      return this->exact_position_ >= static_cast<int32_t>(this->target_position_) &&
             this->exact_tilt_ >= static_cast<int32_t>(this->target_tilt_);

    case COVER_OPERATION_CLOSING:
      return this->exact_position_ <= static_cast<int32_t>(this->target_position_) &&
             this->exact_tilt_ <= static_cast<int32_t>(this->target_tilt_);

    case COVER_OPERATION_IDLE:
    default:
      return true;
  }
}

void VenetianBlinds::start_direction_(CoverOperation operation) {
  if (operation == this->current_operation &&
      operation != COVER_OPERATION_IDLE) {
    return;
  }

  this->recompute_position_();

  Trigger<> *trigger = nullptr;

  switch (operation) {
    case COVER_OPERATION_IDLE:
      trigger = this->stop_trigger_;
      break;

    case COVER_OPERATION_OPENING:
      this->last_operation_ = operation;
      trigger = this->open_trigger_;
      break;

    case COVER_OPERATION_CLOSING:
      this->last_operation_ = operation;
      trigger = this->close_trigger_;
      break;

    default:
      return;
  }

  this->current_operation = operation;

  const uint32_t now = millis();
  this->start_dir_time_ = now;
  this->last_recompute_time_ = now;

  this->stop_prev_trigger_();
  trigger->trigger();
  this->prev_command_trigger_ = trigger;
}

void VenetianBlinds::recompute_position_() {
  if (this->current_operation == COVER_OPERATION_IDLE)
    return;

  const uint32_t now = millis();

  const uint32_t actuator_start_time =
      this->start_dir_time_ + this->actuator_activation_duration_;

  if (now <= actuator_start_time) {
    return;
  }

  int direction;
  uint32_t action_duration;
  int32_t tilt_boundary;

  switch (this->current_operation) {
    case COVER_OPERATION_OPENING:
      direction = 1;
      action_duration = this->open_net_duration_;
      tilt_boundary = static_cast<int32_t>(this->tilt_duration_);
      break;

    case COVER_OPERATION_CLOSING:
      direction = -1;
      action_duration = this->close_net_duration_;
      tilt_boundary = 0;
      break;

    default:
      return;
  }

  const uint32_t movement_start_time =
      this->last_recompute_time_ < actuator_start_time
          ? actuator_start_time
          : this->last_recompute_time_;

  const uint32_t cover_moving_time = now - movement_start_time;

  this->exact_tilt_ += direction * static_cast<int32_t>(cover_moving_time);

  const int32_t tilt_overflow =
      direction * (this->exact_tilt_ - tilt_boundary);

  this->exact_tilt_ = std::clamp<int32_t>(
      this->exact_tilt_, 0, static_cast<int32_t>(this->tilt_duration_));

  if (tilt_overflow > 0) {
    this->exact_position_ += direction * tilt_overflow;
    this->exact_position_ = std::clamp<int32_t>(
        this->exact_position_, 0, static_cast<int32_t>(action_duration));
  }

  this->position =
      action_duration == 0
          ? 0.0f
          : this->exact_position_ / static_cast<float>(action_duration);

  this->tilt =
      this->tilt_duration_ == 0
          ? 0.0f
          : this->exact_tilt_ / static_cast<float>(this->tilt_duration_);

  this->last_recompute_time_ = now;
}

}  // namespace esphome::venetian_blinds
