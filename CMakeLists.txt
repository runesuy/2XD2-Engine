cmake_minimum_required(VERSION 3.28.3)
project(2XD2_Engine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(core)
add_subdirectory(renderer)
add_subdirectory(framework)

enable_testing()
add_subdirectory(tests)