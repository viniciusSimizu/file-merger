set(LIB_DIR ${CMAKE_SOURCE_DIR}/libs)

add_executable(helper_test helper_test.c)
add_executable(validator_test validator_test.c)

target_link_libraries(helper_test PRIVATE helper)
target_link_libraries(validator_test PRIVATE validator)

target_include_directories(helper_test PUBLIC ${LIB_DIR})
target_include_directories(validator_test PUBLIC ${LIB_DIR})

add_test(NAME run_helper_test COMMAND helper_test)
add_test(NAME run_validator_test COMMAND validator_test)
