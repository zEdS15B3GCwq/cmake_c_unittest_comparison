cmake_minimum_required(VERSION 3.0)
project("unittest comparison" C)

set(TARGET_GROUP production CACHE STRING "Group to build")

add_subdirectory(module_sum)

if(TARGET_GROUP STREQUAL production)
    add_subdirectory(main)

elseif(TARGET_GROUP STREQUAL test_unity)
    include(CTest)

    add_subdirectory(external)
    add_subdirectory(test/unity)

elseif(TARGET_GROUP STREQUAL test_cunit)
    include(CTest)

    add_subdirectory(external)
    add_subdirectory(test/cunit)

elseif(TARGET_GROUP STREQUAL test_libcester)
    include(CTest)

    add_subdirectory(external)
    add_subdirectory(test/libcester)

else()
    message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()
