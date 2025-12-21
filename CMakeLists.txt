cmake_minimum_required(VERSION 3.28.3)
project(2XD2_Engine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(engine/core)
add_subdirectory(engine/renderer)
add_subdirectory(engine/framework)
add_subdirectory(addons/std-addon)

add_subdirectory(examples/pong)

add_library(2XD2_Engine INTERFACE)
target_link_libraries(2XD2_Engine INTERFACE
    2XD2_Engine_Framework
    2XD2_Std_Addon
)

enable_testing()
add_subdirectory(tests)