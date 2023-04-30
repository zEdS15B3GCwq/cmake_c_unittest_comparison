cmake_minimum_required(VERSION 3.20)
project("unittest comparison" C)

set(TARGET_GROUP production CACHE STRING "Group to build")
string(SUBSTRING "${TARGET_GROUP}" 0 5 TARGET_PREFIX)

add_subdirectory(modules)

if(TARGET_GROUP STREQUAL production)
    message(STATUS "Target = production build")
    add_subdirectory(main)

elseif(TARGET_PREFIX STREQUAL test_)
    include(CTest)

    if(TARGET_GROUP STREQUAL test_unity)
        message(STATUS "Target = Unity tests")
        # add_compile_definitions(UNITY_INCLUDE_EXEC_TIME UNITY_USE_COMMAND_LINE_ARGS)
        # add_compile_definitions(UNITY_FIXTURE_NO_EXTRAS)
        add_subdirectory(external)
        add_subdirectory(tests/unity)

    elseif(TARGET_GROUP STREQUAL test_cunit)
        message(STATUS "Target = CUnit tests")
        add_subdirectory(external)
        add_subdirectory(tests/cunit)

    elseif(TARGET_GROUP STREQUAL test_libcester)
        message(STATUS "Target = libcester tests")
        add_subdirectory(external)
        add_subdirectory(tests/libcester)

    elseif(TARGET_GROUP STREQUAL test_glib)
        message(STATUS "Target = glib tests")
        add_subdirectory(tests/glib)

    else()
        message(FATAL_ERROR "Unknown test group specified in TARGET_GROUP")

    endif()

else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")

endif()
