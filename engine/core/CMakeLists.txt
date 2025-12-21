cmake_minimum_required(VERSION 3.28.3)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE CORE_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

add_library(2XD2_Engine_Core ${CORE_SOURCES})

target_include_directories(2XD2_Engine_Core PUBLIC
        include
)

target_include_directories(2XD2_Engine_Core
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
)