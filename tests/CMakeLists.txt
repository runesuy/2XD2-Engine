enable_testing()

file(GLOB_RECURSE TEST_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

add_executable(2XD2_Engine_Tests ${TEST_SOURCES})

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)

target_link_libraries(2XD2_Engine_Tests PUBLIC
        2XD2_Engine_Renderer  # The library we are testing
        2XD2_Engine_Core      # Core library if needed
        2XD2_Engine_Framework # Framework library if needed
        gtest_main # GTest's main executable runner
        gmock       # GMock for mocking functionalities
)

target_include_directories(2XD2_Engine_Tests PUBLIC core renderer framework)


include(GoogleTest)
gtest_discover_tests(2XD2_Engine_Tests WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
