cmake_minimum_required(VERSION 3.27.7)
project(estevan)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(DEBUG ON)

if (DEBUG)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

add_subdirectory(lib)

enable_testing()
add_subdirectory(test)
