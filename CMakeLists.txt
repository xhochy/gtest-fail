cmake_minimum_required(VERSION 3.0)

project(GTestFail)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

find_package(GTest)

add_executable(test test.cpp)

target_link_libraries(test GTest::gtest GTest::gtest_main)
