cmake_minimum_required(VERSION 3.28.3)

file(GLOB_RECURSE FRAMEWORK_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

add_library(2XD2_Engine_Framework ${FRAMEWORK_SOURCES})

# Nlohmann JSON FetchContent
include(FetchContent)

FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
)

FetchContent_MakeAvailable(json)

target_include_directories(2XD2_Engine_Framework PUBLIC
        include
        lib
)

target_link_libraries(2XD2_Engine_Framework PUBLIC
        2XD2_Engine_Core
        2XD2_Engine_Renderer
        nlohmann_json::nlohmann_json
)
