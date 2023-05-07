add_executable(single_suite_app single_suite.c)

#target_link_directories(single_suite_app PUBLIC "${GLIB_LIB_DIR}")
#target_link_libraries(single_suite_app utils "${GLIB_LIB_DIR}/glib-2.0.lib")
#target_include_directories(single_suite_app PUBLIC "${GLIB_INCLUDE_DIR}/glib-2.0" "${GLIB_LIB_DIR}/glib-2.0/include")

target_link_libraries(single_suite_app utils)

add_test(single_suite_test single_suite_app v)