set(LIB_DIR ${CMAKE_SOURCE_DIR}/libs)

add_executable(helper_test helper_test.c)

target_link_libraries(helper_test PRIVATE helper)

target_include_directories(helper_test PUBLIC ${LIB_DIR})
