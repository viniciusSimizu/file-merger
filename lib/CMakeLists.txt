add_library(helper helper.c)
add_library(validator validator.c)

target_include_directories(helper PUBLIC .)
target_include_directories(validator PUBLIC .)
