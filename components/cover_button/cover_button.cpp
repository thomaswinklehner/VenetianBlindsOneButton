#include "cover_button.h"

#include <algorithm>

#include "esphome/core/hal.h"
#include "esphome/core/log.h"

namespace esphome::cover_button {

static const char *const TAG = "cover_button";

CoverButtonController *CoverButtonController::controllers_[MAX_CONTROLLERS]{};
size_t CoverButtonController::controller_count_{0};
CoverButtonController::Direction CoverButtonController::group_direction_{DOWN};

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

  controllers_[controller_count_++] = this;
  this->input_->add_on_state_callback(
      [this](bool state) { this->handle_input_(state); });
}

void CoverButtonController::dump_config() {
  ESP_LOGCONFIG(TAG, "Cover button controller:");
  ESP_LOGCONFIG(TAG, "  Tilt enabled: %s", YESNO(this->tilt_enabled_));
  ESP_LOGCONFIG(TAG, "  Tilt step: %.0f%%", this->tilt_step_ * 100.0f);
  ESP_LOGCONFIG(TAG, "  Press limits: %lums / %lums / %lums",
                static_cast<unsigned long>(this->short_press_max_),
                static_cast<unsigned long>(this->stop_press_max_),
                static_cast<unsigned long>(this->all_press_max_));
}

void CoverButtonController::handle_input_(bool state) {
  const uint32_t now = millis();
  if (state) {
    this->pressed_at_ = now;
    this->press_active_ = true;
    return;
  }

  if (!this->press_active_)
    return;

  this->press_active_ = false;
  const uint32_t duration = now - this->pressed_at_;
  if (duration < this->short_press_max_) {
    this->short_press();
  } else if (duration < this->stop_press_max_) {
    this->stop_press();
  } else if (duration <= this->all_press_max_) {
    this->all_press();
  }
}

void CoverButtonController::short_press() {
  // Roller covers intentionally do nothing on a short press.
  if (!this->tilt_enabled_ || this->cover_ == nullptr)
    return;

  if (this->cover_->current_operation != cover::COVER_OPERATION_IDLE)
    return;

  if (!this->cover_->get_traits().get_supports_tilt()) {
    ESP_LOGW(TAG, "Short tilt ignored: configured cover has no tilt support");
    return;
  }

  const float old_tilt = this->cover_->tilt;
  const float direction = group_direction_ == UP ? 1.0f : -1.0f;
  const float new_tilt = std::clamp(
      old_tilt + direction * this->tilt_step_, 0.0f, 1.0f);

  if (new_tilt == old_tilt)
    return;

  this->cover_->make_call().set_tilt(new_tilt).perform();
}

void CoverButtonController::stop_press() {
  if (this->cover_ == nullptr ||
      this->cover_->current_operation == cover::COVER_OPERATION_IDLE)
    return;

  this->cover_->make_call().set_command_stop().perform();
}

void CoverButtonController::all_press() {
  move_all_(group_direction_ == DOWN ? UP : DOWN);
}

void CoverButtonController::open_all() { move_all_(UP); }

void CoverButtonController::close_all() { move_all_(DOWN); }

void CoverButtonController::move_all_(Direction direction) {
  group_direction_ = direction;
  for (size_t index = 0; index < controller_count_; index++) {
    if (controllers_[index] != nullptr)
      controllers_[index]->move_(direction);
  }
}

void CoverButtonController::move_(Direction direction) {
  if (this->cover_ == nullptr)
    return;

  auto call = this->cover_->make_call();
  if (direction == UP)
    call.set_command_open();
  else
    call.set_command_close();
  call.perform();
}

}  // namespace esphome::cover_button
