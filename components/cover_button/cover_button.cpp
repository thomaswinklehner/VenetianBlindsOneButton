#include "cover_button.h"

#include "esphome/core/hal.h"
#include "esphome/core/log.h"

namespace esphome::cover_button {

static const char *const TAG = "cover_button";

CoverButtonController *CoverButtonController::controllers_[MAX_CONTROLLERS]{};
size_t CoverButtonController::controller_count_{0};
bool CoverButtonController::wind_alarm_active_{false};

void CoverButtonController::setup() {
  if (this->cover_ == nullptr || this->input_ == nullptr) {
    this->mark_failed();
    return;
  }

  if (controller_count_ >= MAX_CONTROLLERS) {
    ESP_LOGE(TAG, "Too many cover button controllers");
    this->mark_failed();
    return;
  }

  // Always treat UP as the last direction after a restart, so the first
  // button press moves the cover down.
  this->last_direction_ = UP;

  controllers_[controller_count_++] = this;
  this->cover_->add_on_state_callback(
      [this]() { this->update_last_direction_(); });
  this->input_->add_on_state_callback(
      [this](bool state) { this->handle_input_(state); });

  if (wind_alarm_active_)
    this->move_(UP);
}

void CoverButtonController::loop() {
  if (this->cover_ == nullptr)
    return;

  if (wind_alarm_active_) {
    if (this->needs_movement_(UP))
      this->move_(UP);
    return;
  }

  // A cover started from an idle button press must keep moving while held.
  if (this->press_active_ && this->needs_movement_(this->press_direction_))
    this->move_(this->press_direction_);
}

void CoverButtonController::dump_config() {
  ESP_LOGCONFIG(TAG, "Cover button controller:");
  ESP_LOGCONFIG(TAG, "  Stop on release before: %lums",
                static_cast<unsigned long>(this->stop_release_max_));
  ESP_LOGCONFIG(TAG, "  Move all on release at/after: %lums",
                static_cast<unsigned long>(this->group_release_min_));
}

void CoverButtonController::handle_input_(bool state) {
  const uint32_t now = millis();

  if (state) {
    if (wind_alarm_active_) {
      this->press_active_ = false;
      this->ignore_release_ = true;
      return;
    }

    if (this->cover_ == nullptr)
      return;

    if (this->cover_->current_operation != cover::COVER_OPERATION_IDLE) {
      this->update_last_direction_();
      this->stop_();
      this->press_active_ = false;
      this->ignore_release_ = true;
      return;
    }

    this->pressed_at_ = now;
    this->press_active_ = true;
    this->ignore_release_ = false;
    this->press_direction_ = opposite_(this->last_direction_);
    this->move_(this->press_direction_);
    return;
  }

  if (this->ignore_release_) {
    this->ignore_release_ = false;
    return;
  }

  if (!this->press_active_)
    return;

  this->press_active_ = false;
  const uint32_t duration = now - this->pressed_at_;

  if (duration < this->stop_release_max_) {
    this->stop_();
  } else if (duration >= this->group_release_min_) {
    move_all_(this->press_direction_);
  }
  // Between the two limits, the selected cover simply keeps moving.
}

void CoverButtonController::set_wind_alarm_active(bool active) {
  if (wind_alarm_active_ == active)
    return;

  wind_alarm_active_ = active;
  ESP_LOGI(TAG, "Wind alarm %s", active ? "ACTIVE" : "cleared");

  if (active)
    move_all_(UP);
}

void CoverButtonController::move_all_(Direction direction) {
  for (size_t index = 0; index < controller_count_; index++) {
    auto *controller = controllers_[index];
    if (controller == nullptr)
      continue;

    if (controller->press_active_) {
      controller->press_active_ = false;
      controller->ignore_release_ = true;
    }
    controller->move_(direction);
  }
}

void CoverButtonController::update_last_direction_() {
  if (this->cover_ == nullptr)
    return;

  if (this->cover_->current_operation == cover::COVER_OPERATION_OPENING)
    this->last_direction_ = UP;
  else if (this->cover_->current_operation == cover::COVER_OPERATION_CLOSING)
    this->last_direction_ = DOWN;
}

bool CoverButtonController::needs_movement_(Direction direction) const {
  if (this->cover_ == nullptr)
    return false;

  if (direction == UP) {
    if (this->cover_->current_operation == cover::COVER_OPERATION_CLOSING)
      return true;
    if (this->cover_->current_operation == cover::COVER_OPERATION_OPENING)
      return false;
    if (this->cover_->position < cover::COVER_OPEN - POSITION_EPSILON)
      return true;
    return this->cover_->get_traits().get_supports_tilt() &&
           this->cover_->tilt < cover::COVER_OPEN - POSITION_EPSILON;
  }

  if (this->cover_->current_operation == cover::COVER_OPERATION_OPENING)
    return true;
  if (this->cover_->current_operation == cover::COVER_OPERATION_CLOSING)
    return false;
  if (this->cover_->position > cover::COVER_CLOSED + POSITION_EPSILON)
    return true;
  return this->cover_->get_traits().get_supports_tilt() &&
         this->cover_->tilt > cover::COVER_CLOSED + POSITION_EPSILON;
}

void CoverButtonController::stop_() {
  if (this->cover_ == nullptr ||
      this->cover_->current_operation == cover::COVER_OPERATION_IDLE)
    return;

  this->cover_->make_call().set_command_stop().perform();
}

void CoverButtonController::move_(Direction direction) {
  if (this->cover_ == nullptr)
    return;

  this->last_direction_ = direction;
  auto call = this->cover_->make_call();
  if (direction == UP)
    call.set_command_open();
  else
    call.set_command_close();
  call.perform();
}

}  // namespace esphome::cover_button
