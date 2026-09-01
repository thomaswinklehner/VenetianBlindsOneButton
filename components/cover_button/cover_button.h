#pragma once

#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/components/cover/cover.h"
#include "esphome/core/component.h"

namespace esphome::cover_button {

class CoverButtonController : public Component {
 public:
  enum Direction : int8_t {
    DOWN = -1,
    UP = 1,
  };

  void setup() override;
  void dump_config() override;

  void set_cover(cover::Cover *cover) { this->cover_ = cover; }
  void set_input(binary_sensor::BinarySensor *input) { this->input_ = input; }
  void set_tilt_enabled(bool enabled) { this->tilt_enabled_ = enabled; }
  void set_tilt_step(float step) { this->tilt_step_ = step; }
  void set_short_press_max(uint32_t duration) {
    this->short_press_max_ = duration;
  }
  void set_stop_press_max(uint32_t duration) {
    this->stop_press_max_ = duration;
  }
  void set_all_press_max(uint32_t duration) {
    this->all_press_max_ = duration;
  }

  void short_press();
  void stop_press();
  void all_press();
  void open_all();
  void close_all();

 protected:
  static constexpr size_t MAX_CONTROLLERS = 32;

  static CoverButtonController *controllers_[MAX_CONTROLLERS];
  static size_t controller_count_;
  static Direction group_direction_;

  static void move_all_(Direction direction);
  void handle_input_(bool state);
  void move_(Direction direction);

  cover::Cover *cover_{nullptr};
  binary_sensor::BinarySensor *input_{nullptr};
  bool tilt_enabled_{false};
  float tilt_step_{0.10f};
  uint32_t short_press_max_{1000};
  uint32_t stop_press_max_{2000};
  uint32_t all_press_max_{5000};
  uint32_t pressed_at_{0};
  bool press_active_{false};
};

}  // namespace esphome::cover_button
