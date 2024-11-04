#include "binaryio.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include "image_types.hpp"
#include <cstdint>

// Constants for readability
constexpr int MaxByteValue = 255;
constexpr int ThreeBytesPerPixel = 3;
constexpr int SixBytesPerPixel = 6;

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

void write_ppm(const std::string& file_path, const Image& image) {
    // Open the file in binary mode
    std::ofstream out_file(file_path, std::ios::binary);
    if (!out_file) {
        throw std::runtime_error("Could not open file for writing: " + file_path);
    }

    // Write the PPM header
    out_file << "P6\n" << image.width << " " << image.height << "\n" << image.max_color_value << "\n";

    // Determine if each color channel is 1 byte or 2 bytes based on max_color_value
    bool use_1_byte_per_channel = (image.max_color_value <= MaxByteValue);

    // Write pixel data
    for (const auto& pixel : image.pixels) {
        if (use_1_byte_per_channel) {
            // 1 byte per color channel (8-bit)
            uint8_t r = static_cast<uint8_t>(pixel.r);
            uint8_t g = static_cast<uint8_t>(pixel.g);
            uint8_t b = static_cast<uint8_t>(pixel.b);
            out_file.write(reinterpret_cast<const char*>(&r), sizeof(r)); // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
            out_file.write(reinterpret_cast<const char*>(&g), sizeof(g)); // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
            out_file.write(reinterpret_cast<const char*>(&b), sizeof(b)); // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
        } else {
            // 2 bytes per color channel (16-bit), in big endian
            uint16_t r = pixel.r;
            uint16_t g = pixel.g;
            uint16_t b = pixel.b;

            // Writing each color channel as 2 bytes in big-endian order
            uint8_t r_high = static_cast<uint8_t>((r >> 8) & 0xFF);
            uint8_t r_low = static_cast<uint8_t>(r & 0xFF);
            uint8_t g_high = static_cast<uint8_t>((g >> 8) & 0xFF);
            uint8_t g_low = static_cast<uint8_t>(g & 0xFF);
            uint8_t b_high = static_cast<uint8_t>((b >> 8) & 0xFF);
            uint8_t b_low = static_cast<uint8_t>(b & 0xFF);

            out_file.write(reinterpret_cast<const char*>(&r_high), sizeof(r_high)); // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
            out_file.write(reinterpret_cast<const char*>(&r_low), sizeof(r_low));   // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
            out_file.write(reinterpret_cast<const char*>(&g_high), sizeof(g_high)); // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
            out_file.write(reinterpret_cast<const char*>(&g_low), sizeof(g_low));   // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
            out_file.write(reinterpret_cast<const char*>(&b_high), sizeof(b_high)); // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
            out_file.write(reinterpret_cast<const char*>(&b_low), sizeof(b_low));   // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
        }
    }

    // Close the file
    out_file.close();

    if (!out_file) {
        throw std::runtime_error("Error writing to file: " + file_path);
    }
}
