cmake_minimum_required(VERSION 3.27.7)
project(estevan)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)

enable_testing()
add_subdirectory(test)
