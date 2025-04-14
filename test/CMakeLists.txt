# Download GoogleTest (FetchContent is modern way to include it)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable test support
enable_testing()

# Build the test binary
add_executable(test_suite
    test_prng.cpp
)

# Link it with your libraries
target_link_libraries(test_suite
    gtest_main
    libprng
    libbench
)

# Register tests with CTest
include(GoogleTest)
gtest_discover_tests(test_suite)

