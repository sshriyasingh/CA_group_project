#include <gtest/gtest.h>
#include "common/binaryio.hpp"       // Include the read_ppm function
#include <string>

TEST(ReadPPMTest, ValidPPMFile) {
    // Load the test PPM file
    std::string file_path = "/Users/shriyasingh/Desktop/CA_group_project/test_resources/resources/ppm1.ppm";

    Image image = read_ppm(file_path);

    EXPECT_EQ(image.width, 2);
    EXPECT_EQ(image.height, 2);
    EXPECT_EQ(image.max_color_value, 255);

    ASSERT_EQ(image.pixels.size(), 4);

    EXPECT_EQ(image.pixels[0].r, 255); EXPECT_EQ(image.pixels[0].g, 0); EXPECT_EQ(image.pixels[0].b, 0);
    EXPECT_EQ(image.pixels[1].r, 0);   EXPECT_EQ(image.pixels[1].g, 255); EXPECT_EQ(image.pixels[1].b, 0);
    EXPECT_EQ(image.pixels[2].r, 0);   EXPECT_EQ(image.pixels[2].g, 0);   EXPECT_EQ(image.pixels[2].b, 255);
    EXPECT_EQ(image.pixels[3].r, 255); EXPECT_EQ(image.pixels[3].g, 255); EXPECT_EQ(image.pixels[3].b, 0);
}

TEST(ReadPPMTest, InvalidMagicNumber) {
    std::string file_path = "test_resources/resources/invalid_magic.ppm";
    EXPECT_THROW(read_ppm(file_path), std::runtime_error);
}
