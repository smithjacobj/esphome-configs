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

void static_colors(AddressableLight &it, std::vector<Color> colors) {
  for (int i = 0; i < it.size(); i++) {
    it[i] = colors[i % colors.size()];
  }
}

namespace {
  std::random_device rd;
  std::minstd_rand gen{rd()};
  std::uniform_int_distribution<uint32_t> delay_generator{500, 5000};
  std::uniform_int_distribution<uint32_t> light_selector{};

  std::unordered_map<int, uint32_t> delay_map{};
}

void glimmer(const int id, AddressableLight &it, const Color& current_color) {
  for (int i = 0; i < it.size(); i++) {
    it[i] = current_color;
  }

  if (delay_map[id] > millis()) {
    return;
  }

  delay_map[id] = millis() + delay_generator(gen);
  size_t light_index = light_selector(gen) % it.size();
  it[light_index] = BLACK;
}
