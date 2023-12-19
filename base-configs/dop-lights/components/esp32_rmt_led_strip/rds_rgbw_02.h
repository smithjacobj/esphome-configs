#pragma once

#ifdef USE_ESP32

#include "led_strip.h"

#include "esphome/components/light/light_state.h"

#include <driver/rmt.h>

namespace esphome {
namespace esp32_rmt_led_strip {

enum RDSRGBW02Color : uint8_t {
  RDS_RGBW_02_OFF = 0,
  RDS_RGBW_02_RED,
  RDS_RGBW_02_GREEN,
  RDS_RGBW_02_BLUE,
  RDS_RGBW_02_WHITE,
  RDS_RGBW_02_PURPLE,
  RDS_RGBW_02_YELLOW,
  RDS_RGBW_02_CYAN,
};

class RDSRGBW02RMTView final : public RMTView {
 public:
  int generate_rmt_items(const int index, const uint8_t *src, rmt_item32_t *dest, light::LightState *state) override;
};

};  // namespace esp32_rmt_led_strip
};  // namespace esphome

#endif
