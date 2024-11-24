#pragma once

#include <random>
#include <unordered_map>

const Color RED{255, 0, 0, 0};
const Color GREEN{0, 255, 0, 0};
const Color BLUE{0, 0, 255, 0};
const Color YELLOW{255, 255, 0, 0};
const Color CYAN{0, 255, 255, 0};
const Color MAGENTA{255, 0, 255, 0};
const Color PURPLE{127, 0, 255, 0};
const Color WHITE{0, 0, 0, 255};
const Color BLACK{0, 0, 0, 0};

const Color GOLD{255, 140, 0, 0};
const Color REDORANGE{255, 112, 0, 0};
const Color CHARTREUSE{155, 255, 0, 0};

namespace pastel {
const Color GREEN{0, 255, 100, 0};
const Color YELLOW{255, 255, 0, 0};
const Color BLUE{0, 160, 255, 0};
const Color PINK{255, 0, 160, 0};
}  // namespace pastel

void static_colors(AddressableLight& it, std::vector<Color> colors) {
  for (int i = 0; i < it.size(); i++) {
    it[i] = colors[i % colors.size()];
  }
}

namespace {
std::random_device                      rd;
std::minstd_rand                        gen{rd()};
std::uniform_int_distribution<uint32_t> delay_generator{200, 2000};
std::uniform_int_distribution<uint32_t> light_selector{};

std::unordered_map<size_t, uint32_t> delay_map{};
}  // namespace

void shimmer(AddressableLight& it, const Color& current_color) {
  const size_t id = reinterpret_cast<size_t>(&it);

  for (int i = 0; i < it.size(); i++) {
    it[i] = current_color;
  }

  if (delay_map[id] > millis()) {
    return;
  }

  delay_map[id]      = millis() + delay_generator(gen);
  size_t light_index = light_selector(gen) % it.size();
  it[light_index]    = BLACK;
}

void palette_randomizer(AddressableLight& it, std::vector<Color> colors) {
  for (int i = 0; i < it.size(); i++) {
    size_t color_index = light_selector(gen) % colors.size();
    it[i]              = colors[color_index];
  }
}

namespace {
struct PaletteRotationState {
  uint32_t colorOffset;
};

std::unordered_map<size_t, PaletteRotationState> palette_rotation_state_map{};
}  // namespace

void palette_rotation(AddressableLight& it, std::vector<Color> colors) { 
  const size_t id = reinterpret_cast<size_t>(&it);
  PaletteRotationState& state{palette_rotation_state_map[id]};

  size_t color_index = (++state.colorOffset) % colors.size();
  for (int i = 0; i < it.size(); i++) {
    it[i] = colors[color_index];
  }
}

namespace {
struct PaletteMarqueeState {
  uint32_t colorOffset;
};

std::unordered_map<size_t, PaletteMarqueeState> palette_marquee_state_map{};
}  // namespace

void palette_marquee(AddressableLight& it, std::vector<Color> colors) {
  const size_t         id = reinterpret_cast<size_t>(&it);
  PaletteMarqueeState& state{palette_marquee_state_map[id]};

  for (int i = 0; i < it.size(); i++) {
    const uint32_t colorIndex = (state.colorOffset + i) % colors.size();
    it[i]                     = colors[colorIndex];
  }

  state.colorOffset = (state.colorOffset + 1) % colors.size();
}
