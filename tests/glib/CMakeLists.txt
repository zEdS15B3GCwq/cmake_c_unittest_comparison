set(GSTREAMER_ENV_VARNAME "GSTREAMER_1_0_ROOT_MSVC_X86_64")
if(NOT DEFINED ENV{${GSTREAMER_ENV_VARNAME}})
    message(FATAL_ERROR "Gstreamer environment variable \"${GSTREAMER_ENV_VARNAME}\" missing.")
endif()

set(GLIB_PREFIX $ENV{GSTREAMER_1_0_ROOT_MSVC_X86_64})
message("Using Gstreamer installation located at \"${GLIB_PREFIX}\"")
cmake_path(SET GLIB_PREFIX_DIR NORMALIZE "${GLIB_PREFIX}")
cmake_path(APPEND GLIB_PREFIX_DIR "include" OUTPUT_VARIABLE GLIB_INCLUDE_DIR)
cmake_path(APPEND GLIB_PREFIX_DIR "lib" OUTPUT_VARIABLE GLIB_LIB_DIR)

link_directories("${GLIB_LIB_DIR}")

#link_libraries(utils "${GLIB_LIB_DIR}/glib-2.0.lib")
cmake_path(APPEND GLIB_LIB_DIR "glib-2.0.lib" OUTPUT_VARIABLE lib1)
link_libraries(utils "${lib1}")

#include_directories("${GLIB_INCLUDE_DIR}/glib-2.0" "${GLIB_LIB_DIR}/glib-2.0/include")
cmake_path(APPEND GLIB_INCLUDE_DIR "glib-2.0" OUTPUT_VARIABLE incl1)
cmake_path(APPEND GLIB_LIB_DIR "glib-2.0" "include" OUTPUT_VARIABLE incl2)
include_directories("${incl1}" "${incl2}")

add_subdirectory(single_suite)
#add_subdirectory(multi_suite)
