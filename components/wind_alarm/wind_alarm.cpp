#include "wind_alarm.h"

#include "esphome/core/log.h"

namespace esphome::wind_alarm {

static const char *const TAG = "wind_alarm";

void WindAlarmController::setup() {
  if (this->input_ == nullptr) {
    this->mark_failed();
    return;
  }

  this->input_->add_on_state_callback(
      [this](bool state) { this->handle_state_(state); });

  if (this->input_->has_state())
    this->handle_state_(this->input_->state);
}

void WindAlarmController::dump_config() {
  ESP_LOGCONFIG(TAG, "Wind alarm controller:");
  ESP_LOGCONFIG(TAG, "  Active low: %s", YESNO(this->active_low_));
}

void WindAlarmController::handle_state_(bool state) {
  const bool active = this->active_low_ ? !state : state;
  cover_button::CoverButtonController::set_wind_alarm_active(active);
}

}  // namespace esphome::wind_alarm
