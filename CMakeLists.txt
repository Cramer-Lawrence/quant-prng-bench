cmake_minimum_required(VERSION 3.14)
project(QuantPRNGBench)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libprng)
add_subdirectory(libbench)
add_subdirectory(benchmarks)
add_subdirectory(test)
