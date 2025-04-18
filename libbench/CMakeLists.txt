add_library(libbench
	src/timer.cpp
	src/BenchReport.cpp
)

target_include_directories(libbench PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
