cmake_minimum_required(VERSION 3.31.6)

file(GLOB_RECURSE RENDERER_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

add_library(2XD2_Engine_Renderer ${RENDERER_SOURCES})

target_include_directories(2XD2_Engine_Renderer PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

find_package(SFML 2.6 COMPONENTS system window graphics REQUIRED)

target_link_libraries(2XD2_Engine_Renderer
        PUBLIC
        sfml-graphics sfml-window sfml-system
        2XD2_Engine_Core
)