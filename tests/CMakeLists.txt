# 1. Enable Testing (Crucial for CTest)
enable_testing()

# 2. Download and Configure Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

add_subdirectory(core)
add_subdirectory(framework)
add_subdirectory(renderer)
