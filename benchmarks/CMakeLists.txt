add_library(benchmarks
	src/bench.cpp
)

target_include_directories(benchmarks PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
