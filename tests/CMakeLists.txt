# ---------------------------------
# Download and link GoogleTest code
# ---------------------------------
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24
# https://github.com/ethereum/solidity/pull/13429
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

# Adapted from googletest CMake instructions
# https://github.com/google/googletest/blob/main/googletest/README.md
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now link against gtest_main.
add_executable(loggertest LoggerTest.cpp)
target_link_libraries(loggertest logger gtest_main)

add_executable(threadtest ThreadTest.cpp)
target_link_libraries(threadtest logger gtest_main)

# TODO run these together
# https://stackoverflow.com/questions/20378549/how-to-run-all-gtest-files-at-once-using-cmake
