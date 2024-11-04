#include "imageio.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

Image read_ppm(const std::string& file_path) {
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Could not open file: " + file_path);
    }

    // Read and validate the magic number
    std::string magic_number;
    file >> magic_number;
    if (magic_number != "P6") {
        throw std::runtime_error("Invalid PPM format: Magic number is not 'P6'");
    }

    // Read width, height, and max color value
    int width, height, max_color_value;
    file >> width >> height >> max_color_value;
    if (width <= 0 || height <= 0 || max_color_value <= 0 || max_color_value > 65535) {
        throw std::runtime_error("Invalid PPM header values");
    }

    // Consume the newline character after max color value
    file.ignore();

    // Prepare the Image object
    Image image;
    image.width = width;
    image.height = height;
    image.max_color_value = max_color_value;

    // Determine if each color channel is 1 byte or 2 bytes
    bool is_two_byte_color = (max_color_value > 255);
    int pixel_size = is_two_byte_color ? 6 : 3;
    image.pixels.resize(width * height);

    // Read pixel data
    for (int i = 0; i < width * height; ++i) {
        if (is_two_byte_color) {
            // 6 bytes per pixel (2 bytes for each color channel)
            uint16_t r = (file.get() << 8) | file.get();
            uint16_t g = (file.get() << 8) | file.get();
            uint16_t b = (file.get() << 8) | file.get();
            image.pixels[i] = {r, g, b};
        } else {
            // 3 bytes per pixel (1 byte for each color channel)
            uint8_t r = file.get();
            uint8_t g = file.get();
            uint8_t b = file.get();
            image.pixels[i] = {r, g, b};
        }
    }

    if (file.fail()) {
        throw std::runtime_error("Error reading pixel data from file");
    }

    return image;
}
