#ifndef BINARY_IO_HPP
#define BINARY_IO_HPP

#include <string>
#include "image_types.hpp"

Image read_ppm(const std::string& file_path);
void write_ppm(const std::string& file_path, const Image& image);
#endif
