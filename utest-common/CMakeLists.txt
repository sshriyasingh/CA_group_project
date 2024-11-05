add_executable(utest-common
        writeppm_test.cpp
        readppm_test.cpp
        metadata_test.cpp
)  # Add other test files if necessary
target_link_libraries(utest-common PRIVATE common GTest::gtest_main)
