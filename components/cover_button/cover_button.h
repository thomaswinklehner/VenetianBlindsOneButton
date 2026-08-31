#pragma once

#include "esphome/components/cover/cover.h"

namespace cover_button {

class CoverButtonController {
 public:
  enum Direction : int {
    DOWN = -1,
    UP = 1,
  };

  static constexpr int MAX_CONTROLLERS = 14;

  CoverButtonController();

  void set_cover(esphome::cover::Cover *cover);
  int get_last_direction() const;
  void set_direction(int direction);

  // 0-1 s: tilt only when the cover is idle.
  void short_press();

  // 1-2 s: stop only when the cover is moving.
  void stop_press();

  // 2-5 s: toggle the direction of all registered covers/blinds.
  void long_press();

  void all_press();

  void move_direction(int direction);
  void stop();

 private:
  esphome::cover::Cover *cover_{nullptr};
  int last_direction_{DOWN};

};

extern CoverButtonController button_01;
extern CoverButtonController button_02;
extern CoverButtonController button_03;
extern CoverButtonController button_04;
extern CoverButtonController button_05;
extern CoverButtonController button_06;
extern CoverButtonController button_07;
extern CoverButtonController button_08;
extern CoverButtonController button_09;
extern CoverButtonController button_10;
extern CoverButtonController button_11;
extern CoverButtonController button_12;
extern CoverButtonController button_13;
extern CoverButtonController button_14;

}  // namespace cover_button

using cover_button::button_01;
using cover_button::button_02;
using cover_button::button_03;
using cover_button::button_04;
using cover_button::button_05;
using cover_button::button_06;
using cover_button::button_07;
using cover_button::button_08;
using cover_button::button_09;
using cover_button::button_10;
using cover_button::button_11;
using cover_button::button_12;
using cover_button::button_13;
using cover_button::button_14;
