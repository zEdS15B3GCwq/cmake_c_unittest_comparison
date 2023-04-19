if(TARGET_GROUP STREQUAL test_unity)

# simply add required source files
#    add_library(unity STATIC Unity/src/unity.c)
#    target_include_directories(unity PUBLIC Unity/src)
#    add_library(unity_fixture STATIC Unity/extras/fixture/src/unity_fixture.c)
#    target_include_directories(unity_fixture PUBLIC Unity/extras/fixture/src)

# or use included CMakeLists.txt

    set(UNITY_EXTENSION_FIXTURE yes CACHE BOOL "compile unity with fixtures extension")

    add_subdirectory(unity)

elseif(TARGET_GROUP STREQUAL test_libcester)

    add_library(Cester INTERFACE libcester/include/exotic/cester.h)

    target_include_directories(Cester INTERFACE libcester/include)

elseif(TARGET_GROUP STREQUAL test_cunit)

    set(CUNIT_DISABLE_EXAMPLES yes)
    set(CUNIT_DISABLE_TESTS yes)

    add_subdirectory(cunit/CUnit)

endif()