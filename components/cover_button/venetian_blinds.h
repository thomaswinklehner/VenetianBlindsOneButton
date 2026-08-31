#pragma once

#include "esphome/components/cover/cover.h"
#include "esphome/core/automation.h"
#include "esphome/core/component.h"

namespace esphome::venetian_blinds {

class VenetianBlinds final : public Component, public cover::Cover {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  cover::CoverTraits get_traits() override;
  void control(const cover::CoverCall &call) override;

  Trigger<> *get_open_trigger() const { return this->open_trigger_; }
  Trigger<> *get_close_trigger() const { return this->close_trigger_; }
  Trigger<> *get_stop_trigger() const { return this->stop_trigger_; }

  void set_open_duration(uint32_t value) { this->open_duration_ = value; }
  void set_close_duration(uint32_t value) { this->close_duration_ = value; }
  void set_tilt_duration(uint32_t value) { this->tilt_duration_ = value; }
  void set_actuator_activation_duration(uint32_t value) {
    this->actuator_activation_duration_ = value;
  }
  void set_assumed_state(bool value) { this->assumed_state_ = value; }

 protected:
  Trigger<> *open_trigger_{new Trigger<>()};
  Trigger<> *close_trigger_{new Trigger<>()};
  Trigger<> *stop_trigger_{new Trigger<>()};

  uint32_t open_duration_{0};
  uint32_t close_duration_{0};
  uint32_t tilt_duration_{0};
  uint32_t actuator_activation_duration_{0};
  bool assumed_state_{true};

 private:
  uint32_t start_dir_time_{0};
  uint32_t last_recompute_time_{0};
  uint32_t last_publish_time_{0};

  uint32_t open_net_duration_{0};
  uint32_t close_net_duration_{0};

  uint32_t target_position_{0};
  uint32_t target_tilt_{0};

  int32_t exact_position_{0};
  int32_t exact_tilt_{0};

  Trigger<> *prev_command_trigger_{nullptr};
  cover::CoverOperation last_operation_{cover::COVER_OPERATION_IDLE};

  void stop_prev_trigger_();
  bool is_at_target_() const;
  void start_direction_(cover::CoverOperation operation);
  void recompute_position_();
};

}  // namespace esphome::venetian_blinds
