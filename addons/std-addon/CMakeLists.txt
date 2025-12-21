file(GLOB_RECURSE STD_ADDON_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_library(2XD2_Std_Addon ${STD_ADDON_SOURCES})

target_include_directories(2XD2_Std_Addon PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(2XD2_Std_Addon
        PUBLIC
        2XD2_Engine_Framework
)