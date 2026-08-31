#include "cover_button.h"

#include <algorithm>

namespace cover_button {

namespace {

CoverButtonController *controllers[CoverButtonController::MAX_CONTROLLERS]{};
int controller_count = 0;

void register_controller(CoverButtonController *controller) {
  if (controller == nullptr || controller_count >= CoverButtonController::MAX_CONTROLLERS)
    return;

  controllers[controller_count++] = controller;
}

}  // namespace

CoverButtonController::CoverButtonController() {
  register_controller(this);
}

void CoverButtonController::set_cover(esphome::cover::Cover *cover) {
  this->cover_ = cover;
}

int CoverButtonController::get_last_direction() const {
  return this->last_direction_;
}

void CoverButtonController::set_direction(int direction) {
  this->last_direction_ = direction == UP ? UP : DOWN;
}

void CoverButtonController::short_press() {
  if (this->cover_ == nullptr)
    return;

  // A short press is exclusively for tilt. Do not stop or reverse
  // a running lift movement; the 1-2 s press is the stop command.
  if (this->cover_->current_operation != esphome::cover::COVER_OPERATION_IDLE)
    return;

  const float old_tilt = this->cover_->tilt;
  const float new_tilt =
      this->last_direction_ == UP
          ? std::min(old_tilt + 0.10f, 1.0f)
          : std::max(old_tilt - 0.10f, 0.0f);

  if (new_tilt == old_tilt)
    return;

  auto call = this->cover_->make_call();
  call.set_tilt(new_tilt);
  call.perform();
}

void CoverButtonController::stop_press() {
  if (this->cover_ == nullptr)
    return;

  if (this->cover_->current_operation ==
      esphome::cover::COVER_OPERATION_IDLE)
    return;

  auto call = this->cover_->make_call();
  call.set_command_stop();
  call.perform();
}

void CoverButtonController::long_press() {
  this->all_press();
}

void CoverButtonController::all_press() {
  const int direction = this->last_direction_ == DOWN ? UP : DOWN;

  for (int i = 0; i < controller_count; i++) {
    if (controllers[i] != nullptr)
      controllers[i]->move_direction(direction);
  }
}

void CoverButtonController::move_direction(int direction) {
  if (this->cover_ == nullptr)
    return;

  auto call = this->cover_->make_call();

  if (direction == UP) {
    call.set_command_open();
    this->last_direction_ = UP;
  } else {
    call.set_command_close();
    this->last_direction_ = DOWN;
  }

  call.perform();
}

void CoverButtonController::stop() {
  if (this->cover_ == nullptr)
    return;

  auto call = this->cover_->make_call();
  call.set_command_stop();
  call.perform();
}

}  // namespace cover_button

cover_button::CoverButtonController button_01;
cover_button::CoverButtonController button_02;
cover_button::CoverButtonController button_03;
cover_button::CoverButtonController button_04;
cover_button::CoverButtonController button_05;
cover_button::CoverButtonController button_06;
cover_button::CoverButtonController button_07;
cover_button::CoverButtonController button_08;
cover_button::CoverButtonController button_09;
cover_button::CoverButtonController button_10;
cover_button::CoverButtonController button_11;
cover_button::CoverButtonController button_12;
cover_button::CoverButtonController button_13;
cover_button::CoverButtonController button_14;
