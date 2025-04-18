cmake_minimum_required(VERSION 3.14)
project(QuantPRNGBench)

add_executable(QuantPRNGBench main.cpp)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libprng)
add_subdirectory(libbench)
add_subdirectory(test)
add_subdirectory(libseed)

find_package(OpenSSL REQUIRED)

target_link_libraries(QuantPRNGBench
	libseed
	libbench
	libprng
	OpenSSL::SSL
	OpenSSL::Crypto
)
