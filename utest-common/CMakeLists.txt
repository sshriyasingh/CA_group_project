add_executable(utest-common
<<<<<<< HEAD
        binaryio_test.cpp
        imageio_test.cpp
        metadata_test.cpp)  # Add other test files if necessary
target_link_libraries(utest-common PRIVATE common GTest::gtest_main)
=======
        writeppm_test.cpp
        readppm_test.cpp
        metadata_test.cpp
)  # Add other test files if necessary
target_link_libraries(utest-common PRIVATE common GTest::gtest_main)
>>>>>>> 123a90e358766340348879a1906c4e305a2f46e9
