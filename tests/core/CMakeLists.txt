# Define the source files for your tests
file(GLOB_RECURSE CORE_TEST_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

if (CORE_TEST_SOURCES)

    # 1. Create the executable target
    add_executable(2XD2_Engine_Core_Tests ${CORE_TEST_SOURCES})

    enable_testing()

    # Fetch Gtest
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.17.0
    )
    FetchContent_MakeAvailable(googletest)

    # 2. Set the include directories
    # Link the necessary public headers (GTest and your EngineCore)
    target_include_directories(2XD2_Engine_Core_Tests PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}
    )

    # 3. Link Dependencies (Crucial Step)
    target_link_libraries(2XD2_Engine_Core_Tests PRIVATE
            2XD2_Engine_Core  # The library we are testing
            gtest_main # GTest's main executable runner
            gmock
    )

    # 4. Register tests with CTest
    # This command automatically finds all TEST() blocks in the executable
    # and registers them as individual CTest tests.
    include(GoogleTest)
    gtest_discover_tests(2XD2_Engine_Core_Tests)

else ()
    message("No test sources found in ${CMAKE_CURRENT_SOURCE_DIR}")
endif ()