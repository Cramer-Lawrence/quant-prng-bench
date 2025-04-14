add_library(libprng
	src/lcg.cpp
)

target_include_directories(libprng PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
