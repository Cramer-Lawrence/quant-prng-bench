add_library(libseed
	src/SeedGenerator.cpp
)

target_include_directories(libseed PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/libbench/include
)
