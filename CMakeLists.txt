cmake_minimum_required(VERSION 3.27.7)
project(estevan)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)

add_executable(main main.c)

if (OFF)
	enable_testing()
	add_subdirectory(test)
endif()
