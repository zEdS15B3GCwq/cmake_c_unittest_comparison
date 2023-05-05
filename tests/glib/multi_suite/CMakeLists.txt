add_executable(multi_suite_main_app
    multi_suite_main.c
    multi_suite_a.c
    multi_suite_b.c
)

target_include_directories(multi_suite_main_app PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(multi_suite_main_app utils)

add_test(multi_suite_test multi_suite_main_app)
