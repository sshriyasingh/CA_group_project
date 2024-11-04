<<<<<<< HEAD
# tests/utest-common/CMakeLists.txt
add_executable(utest-common
    metadata_test.cpp
)

=======
add_executable(utest-common binaryio_test.cpp)  # Add other test files if necessary
>>>>>>> df2f1bb933f1c1886cd00677794c993e4f98345a
target_link_libraries(utest-common PRIVATE common GTest::gtest_main)
