cmake_minimum_required(VERSION 3.31.6)

file(GLOB_RECURSE FRAMEWORK_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)


add_library(2XD2_Engine_Framework ${FRAMEWORK_SOURCES})


target_include_directories(2XD2_Engine_Framework PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(2XD2_Engine_Framework PUBLIC
        2XD2_Engine_Core
        2XD2_Engine_Renderer
)