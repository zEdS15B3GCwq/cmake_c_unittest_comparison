if(TARGET_GROUP STREQUAL test_unity)

    add_library(Unity STATIC Unity/src/unity.c)

    target_include_directories(Unity PUBLIC Unity/src)

elseif(TARGET_GROUP STREQUAL test_libcester)

    add_library(Cester INTERFACE libcester/include/exotic/cester.h)

    target_include_directories(Cester INTERFACE libcester/include)

elseif(TARGET_GROUP STREQUAL test_cunit)

    set(CUNIT_DISABLE_EXAMPLES yes)
    set(CUNIT_DISABLE_TESTS yes)

    add_subdirectory(cunit/CUnit)

endif()