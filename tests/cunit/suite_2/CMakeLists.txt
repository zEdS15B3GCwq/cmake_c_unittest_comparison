add_executable(suite_2_app suite_2.c)

target_link_libraries(suite_2_app utils cunit)

add_test(suite_2_test suite_2_app)
