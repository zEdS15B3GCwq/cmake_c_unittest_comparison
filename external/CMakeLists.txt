if(TARGET_GROUP STREQUAL test_unity)

    set(UNITY_EXTENSION_FIXTURE yes CACHE BOOL "compile with fixtures extension")
    # set(UNITY_EXTENSION_MEMORY no CACHE BOOL "do not use memory addon")

    add_subdirectory(unity)

elseif(TARGET_GROUP STREQUAL test_libcester)

#    add_library(Cester INTERFACE libcester/include/exotic/cester.h)

#    target_include_directories(Cester INTERFACE libcester/include)
    

elseif(TARGET_GROUP STREQUAL test_cunit)

    set(CUNIT_DISABLE_EXAMPLES yes)
    set(CUNIT_DISABLE_TESTS yes)

    add_subdirectory(cunit/CUnit)

elseif(TARGET_GROUP STREQUAL test_glib)

    set(GSTREAMER_ENV_VARNAME "GSTREAMER_1_0_ROOT_MSVC_X86_64")
    if(NOT DEFINED ENV{${GSTREAMER_ENV_VARNAME}})
        message(FATAL_ERROR "Gstreamer environment variable \"${GSTREAMER_ENV_VARNAME}\" missing.")
    endif()

    set(GLIB_PREFIX $ENV{GSTREAMER_1_0_ROOT_MSVC_X86_64})
    message("Using Gstreamer installation located at \"${GLIB_PREFIX}\"")
    cmake_path(SET GLIB_PREFIX_DIR NORMALIZE "${GLIB_PREFIX}")
    cmake_path(APPEND GLIB_PREFIX_DIR "include" OUTPUT_VARIABLE GLIB_INCLUDE_DIR)
    cmake_path(APPEND GLIB_PREFIX_DIR "lib" OUTPUT_VARIABLE GLIB_LIB_DIR)
    cmake_path(APPEND GLIB_PREFIX_DIR "bin" OUTPUT_VARIABLE GLIB_BIN_DIR)

    cmake_path(APPEND GLIB_LIB_DIR "glib-2.0.lib" OUTPUT_VARIABLE lib1)
    cmake_path(APPEND GLIB_BIN_DIR "glib-2.0-0.dll" OUTPUT_VARIABLE dll1)
    cmake_path(APPEND GLIB_INCLUDE_DIR "glib-2.0" OUTPUT_VARIABLE incl1)
    cmake_path(APPEND GLIB_LIB_DIR "glib-2.0" "include" OUTPUT_VARIABLE incl2)

    add_library(GLib SHARED IMPORTED GLOBAL)
	set_target_properties(GLib PROPERTIES
        IMPORTED_IMPLIB "${lib1}"
        IMPORTED_LOCATION "${dll1}"
    )
    target_include_directories(GLib INTERFACE "${incl1}" "${incl2}")

endif()