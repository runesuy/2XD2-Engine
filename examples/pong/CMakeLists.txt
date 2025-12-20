
file (GLOB_RECURSE PONG_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_executable(pong-example ${PONG_SOURCES})

target_link_libraries(pong-example PUBLIC
        2XD2_Engine_Framework
        )