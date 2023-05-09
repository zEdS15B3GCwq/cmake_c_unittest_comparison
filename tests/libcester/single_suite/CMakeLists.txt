add_executable(single_suite_app single_suite.c)

target_link_libraries(single_suite_app utils cunit)

add_test(single_suite_test single_suite_app)