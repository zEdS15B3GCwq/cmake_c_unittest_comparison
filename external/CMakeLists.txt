if(TARGET_GROUP STREQUAL test_unity)

    set(UNITY_EXTENSION_FIXTURE yes CACHE BOOL "compile with fixtures extension")
    # set(UNITY_EXTENSION_MEMORY no CACHE BOOL "do not use memory addon")

    add_subdirectory(unity)

elseif(TARGET_GROUP STREQUAL test_libcester)

    add_library(Cester INTERFACE libcester/include/exotic/cester.h)

    target_include_directories(Cester INTERFACE libcester/include)

elseif(TARGET_GROUP STREQUAL test_cunit)

    set(CUNIT_DISABLE_EXAMPLES yes)
    set(CUNIT_DISABLE_TESTS yes)

    add_subdirectory(cunit/CUnit)

endif()