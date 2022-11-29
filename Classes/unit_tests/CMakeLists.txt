cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

project(Tests)
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories()

add_executable(Google_Tests_run DataContainerTest.cpp ../DataContainer.h ../DataContainer.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
