#pragma once

const Color RED{255, 0, 0};
const Color GREEN{0, 255, 0};
const Color BLUE{0, 0, 255};
const Color YELLOW{255, 255, 0};
const Color CYAN{0, 255, 255};
const Color MAGENTA{255, 0, 255};
const Color PURPLE{127, 0, 255};
const Color WHITE{255, 255, 255};

void static_colors(AddressableLight &it, std::vector<Color> colors) {
  for (int i = 0; i < it.size(); i++) {
    it[i] = colors[i % colors.size()];
  }
}
