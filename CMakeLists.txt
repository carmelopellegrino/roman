project(roman CXX)
cmake_minimum_required(VERSION 3.12)

add_executable(example example/example.cpp)
target_include_directories(example PRIVATE include/)
set_target_properties(example PROPERTIES CXX_STANDARD 11)
