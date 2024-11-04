#ifndef IMAGE_TYPES_HPP
#define IMAGE_TYPES_HPP

#include <vector>
#include <cstdint>

struct Pixel {
    uint16_t r, g, b;
};

struct Image {
    int width;
    int height;
    int max_color_value;
    std::vector<Pixel> pixels;
};

#endif
