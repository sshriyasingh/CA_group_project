add_executable(utest-common
    utest-common/image_io_test.cpp
)

target_link_libraries(utest-common PRIVATE common GTest::gtest_main)
add_test(NAME ReadPPMTests COMMAND utest-common)
