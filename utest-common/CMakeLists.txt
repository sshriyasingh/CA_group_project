add_executable(utest-common imageio_test.cpp binaryio_test.cpp
        imageio_test.cpp)  # Add other test files if necessary
target_link_libraries(utest-common PRIVATE common GTest::gtest_main)
