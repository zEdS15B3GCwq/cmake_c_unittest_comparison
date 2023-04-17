add_library(module_sum STATIC sum.c)

target_include_directories(module_sum PUBLIC ${CMAKE_CURRENT_LIST_DIR})
