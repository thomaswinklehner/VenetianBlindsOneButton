#pragma once

#include "esphome/components/binary_sensor/binary_sensor.h"
#include "../cover_button/cover_button.h"
#include "esphome/core/component.h"

namespace esphome::wind_alarm {

class WindAlarmController : public Component {
 public:
  void setup() override;
  void dump_config() override;
  float get_setup_priority() const override {
    return setup_priority::DATA - 1.0f;
  }

  void set_input(binary_sensor::BinarySensor *input) { this->input_ = input; }
  void set_active_low(bool active_low) { this->active_low_ = active_low; }

 protected:
  void handle_state_(bool state);

  binary_sensor::BinarySensor *input_{nullptr};
  bool active_low_{true};
};

}  // namespace esphome::wind_alarm
