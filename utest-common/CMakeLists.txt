# tests/utest-common/CMakeLists.txt
add_executable(utest-common
    metadata_test.cpp
)

target_link_libraries(utest-common PRIVATE common GTest::gtest_main)
