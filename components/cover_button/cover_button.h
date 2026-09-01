#pragma once

#include <cstddef>
#include <cstdint>

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
  void loop() override;
  void dump_config() override;

  void set_cover(cover::Cover *cover) { this->cover_ = cover; }
  void set_input(binary_sensor::BinarySensor *input) { this->input_ = input; }
  void set_stop_release_max(uint32_t duration) {
    this->stop_release_max_ = duration;
  }
  void set_group_release_min(uint32_t duration) {
    this->group_release_min_ = duration;
  }

  static void set_wind_alarm_active(bool active);
  static bool is_wind_alarm_active() { return wind_alarm_active_; }

 protected:
  static constexpr size_t MAX_CONTROLLERS = 32;
  static constexpr float POSITION_EPSILON = 0.001f;

  static CoverButtonController *controllers_[MAX_CONTROLLERS];
  static size_t controller_count_;
  static bool wind_alarm_active_;

  static void move_all_(Direction direction);
  static Direction opposite_(Direction direction) {
    return direction == UP ? DOWN : UP;
  }

  void handle_input_(bool state);
  void update_last_direction_();
  bool needs_movement_(Direction direction) const;
  void stop_();
  void move_(Direction direction);

  cover::Cover *cover_{nullptr};
  binary_sensor::BinarySensor *input_{nullptr};
  Direction last_direction_{UP};
  Direction press_direction_{UP};
  uint32_t stop_release_max_{2000};
  uint32_t group_release_min_{5000};
  uint32_t pressed_at_{0};
  bool press_active_{false};
  bool ignore_release_{false};
};

}  // namespace esphome::cover_button
