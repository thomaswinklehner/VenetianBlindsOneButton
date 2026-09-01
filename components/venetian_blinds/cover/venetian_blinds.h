#pragma once

#include <cstdint>

#include "esphome/components/cover/cover.h"
#include "esphome/core/automation.h"
#include "esphome/core/component.h"

namespace esphome::venetian_blinds {

class VenetianBlinds : public cover::Cover, public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;

  cover::CoverTraits get_traits() override;

  Trigger<> *get_open_trigger() { return &this->open_trigger_; }
  Trigger<> *get_close_trigger() { return &this->close_trigger_; }
  Trigger<> *get_stop_trigger() { return &this->stop_trigger_; }

  void set_open_duration(uint32_t duration) { this->open_duration_ = duration; }
  void set_close_duration(uint32_t duration) {
    this->close_duration_ = duration;
  }
  void set_tilt_duration(uint32_t duration) { this->tilt_duration_ = duration; }
  void set_actuator_activation_duration(uint32_t duration) {
    this->actuator_activation_duration_ = duration;
  }
  void set_assumed_state(bool assumed_state) {
    this->assumed_state_ = assumed_state;
  }

 protected:
  void control(const cover::CoverCall &call) override;
  void start_direction_(cover::CoverOperation direction);
  void stop_previous_trigger_();
  void recompute_state_();
  bool is_at_target_() const;

  Trigger<> open_trigger_;
  Trigger<> close_trigger_;
  Trigger<> stop_trigger_;
  Trigger<> *previous_trigger_{nullptr};

  uint32_t open_duration_{0};
  uint32_t close_duration_{0};
  uint32_t tilt_duration_{0};
  uint32_t actuator_activation_duration_{0};
  uint32_t open_position_duration_{0};
  uint32_t close_position_duration_{0};

  uint32_t activation_until_{0};
  uint32_t last_recompute_time_{0};
  uint32_t last_publish_time_{0};

  float target_position_{0.0f};
  float target_tilt_{0.0f};
  bool assumed_state_{true};
  cover::CoverOperation last_operation_{cover::COVER_OPERATION_CLOSING};
};

}  // namespace esphome::venetian_blinds
