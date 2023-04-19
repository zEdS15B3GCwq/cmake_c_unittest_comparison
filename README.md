# C Unit Test Comparison with CMake

Comparison of C language unit testing frameworks with CMake (CUnit, Unity, cmocka etc)

## 1. Purpose

I'm on the search for a simple unit testing framework for pure C. Some frameworks are more popular and are mentioned in many forum discussions, such as Unity / Ceedling, CUnit, cmocka, but there are plenty other less known ones that could be just as good. I'm looking for one that has informative output, is easy to build / integrate, is easy to learn (no lengthy documentation), and is actively maintained and can be expected to be around for a while (good history, adaptation, number of maintainers). It's all going to be quite superficial, first-impressions level, because I don't want to waste a lot of time getting to know a complex system.

C++ frameworks are excluded (google test, boost test, cppunit and alike) even if they're supposed to work well with C. No mixed code for me.

This is, obviously, a work in progress.

## 2. List of Candidates

1. [GLib testing framework](https://docs.gtk.org/glib/testing.html)
2. [cmocka](https://cmocka.org/)
3. [µnit (munit)](https://nemequ.github.io/munit/)
4. [ctest](https://github.com/bvdberg/ctest) (not the one included in CMake)
5. [Cgreen](https://github.com/cgreen-devs/cgreen)
6. [Criterion](https://github.com/Snaipe/Criterion/)
7. [tau](https://github.com/jasmcaus/tau/)
8. [libcester](https://github.com/exoticlibraries/libcester)

## 3. Impressions

### 3.1 Cunit (Cunity fork)

**Websites**:

- fork homepage: <https://cunity.gitlab.io/cunit/>
- fork repo: <https://gitlab.com/cunity/cunit/-/tree/master/>
- original home: <https://cunit.sourceforge.net/example.html>

**Maintainers**: single developer

**Activity**: inactive; besides a recent version bump, last commit was >1 year ago.

**Popularity**: mentioned in multiple forum discussions; it's a well known and mature library, I guess

**Documentation**: pre-fork CUnit has detailed docs, the new fork's docs don't go much beyond simple usage with the new CUnitCI API.

**Ease of use**: easy; new CUnitCI macros are easy to learn and use for simple use cases; pre-fork API is more complex

**CMake integration**: very easy, project comes with own CMakeFile.txt; no special build dependencies

```CMake
    set(CUNIT_DISABLE_EXAMPLES yes)
    set(CUNIT_DISABLE_TESTS yes)

    add_subdirectory(cunit/CUnit)
```

**Features**: sufficient; fairly good organisation of tests (suites, registry), not so versatile in terms of smart asserts

- [x] tests can be organised into suites, which can added to a registry to be run together
- [x] each suite can have their own suite-level and pre-test setup / teardown functions
- [x] test context shared via global variables
- [x] easy to use with one executable / test code file  (see [single_suite](tests/cunit/single_suite/) example)
- [x] multiple tests / suites can be linked into one executable (though this isn't well documented, see [multi_suite](tests/cunit/multi_suite/) example);
- [x] failed tests show executed code
- [x] distinguishes between fatal and non-fatal assertions, allowing multiple asserts in one test (however, only the last failure is reported - see comments on output)
- [x] JUnit XML output
- [ ] cannot include custom messages in failed test output (unless using `condition && "message"` in assert)
- [ ] variable values not shown in failed tests
- [ ] no direct support for mocking
- [ ] limited selection of assertions, only TRUE/FALSE/EQUAL, PTR, (N)STRING, DOUBLE variants
- [ ] no array-capable assertions
- [ ] no individual test timing

**Output**: terminal + JUnit XML

![CUnit test result output](images/results_cunit.png)

In my opinion, the output is well organised and it's easy to understand what failed. It's good that the failing code is shown. This type of static output isn't suitable for some things, though. For example, when looping over an array and testing each element with an assert, how to show which element is incorrect? Unity has asserts for comparing arrays, and shows the index and value of the incorrect element.

In case of multiple failing assertions in one test, only the last one's code is reported to the command line: only `CU_ASSERT_EQUAL( 99, identity( a ) )` is shown for `single_suite` above. However,the summary also indicates the correct number and the XML output for `single_suite` shows both failed asserts:


```xml
<?xml version="1.0" encoding="UTF-8"?>
<testsuites errors="0" failures="1" tests="4" name="single_suite_app-Results.xml" time="0.000000">
  <testsuite errors="0" failures="1" tests="4" name="cunit_single_suite" time="0.000000">
    <testcase classname="CUnit.cunit_single_suite" name="CUnit Suite init" time="0.000000">
    </testcase>
    <testcase classname="CUnit.cunit_single_suite" name="test_identity_should_pass" time="0.000000">
    </testcase>
    <testcase classname="CUnit.cunit_single_suite" name="test_identity_should_fail" time="0.000000">
      <failure>Function:
File: C:\Code\cmake_c_unittest_comparison\tests\cunit\single_suite\single_suite.c
Line: 27
Assertion Failed:
Condition: '0 == identity( a )'

</failure>
      <failure>Function:
File: C:\Code\cmake_c_unittest_comparison\tests\cunit\single_suite\single_suite.c
Line: 28
Assertion Failed:
Condition: 'CU_ASSERT_EQUAL(99,identity( a ))'

</failure>
    </testcase>
    <testcase classname="CUnit.cunit_single_suite" name="CUnit Suite cleanup" time="0.000000">
    </testcase>
  </testsuite>
</testsuites>
```

### 3.2 Unity

**Websites**:

- home: <http://www.throwtheswitch.org/unity>
- repo: <https://github.com/ThrowTheSwitch/Unity>

**Maintainers**: 100+ contributors; only 1 contributor has committed code in 2023

**Activity**: the last bugfix release was in 2021 Jan; last feature release in 2019 Oct; main maintainer [claims](https://groups.google.com/g/throwtheswitch/c/JKg9GgdeYHw) that development is active and going mostly in the direction of Ceedling and such, and the forums are pretty active too.

**Popularity**: many mentions, seems to be popular

**Documentation**: the docs describe a simple use case and that part is easy to understand, easy to implement and integrate. However, there'a lot beyond that that's hidden in the code and examples. For example, the only references on `unity_fixtures` are comments in the source and the 2nd example - OK, it's not meant to be the main way to use it. Some other things are very difficult to figure out. For example, I tried to get verbose output from the test executable. There's an undocumented function that parses command line arguments (verbose etc) in `unity_internals.h`, and while I was able to link it, it's not doing anything. Perhaps I could figure it out by looking more into it, but I don't understand why this simple functionality isn't more readily available. Apparently, `Ceedling` makes use of it to format output? Also, configuration options that are documented and are supposed to change the output (e.g. `UNITY_OUTPUT_FOR_ECLIPSE`) don't seem to be doing anything.

the framework is pretty simple to use and that usage has good documentation; however, more detailed docs are "hidden" as .md files in the repo, and the only reference on test groups (`unity_fixtures`) is the 2nd example

**Ease of use**: easy; there's a "general" mode that suits 1 exe / code file, and a "test group" functionality; both modes are fairly simple to use

**CMake integration**: Unity is more geared towards Meson, but the project includes `CMakeLists.txt` scripts as well, and there are some instructions on how to include it as a simple source file.

```CMake
# simply add required source files
#    add_library(unity STATIC Unity/src/unity.c)
#    target_include_directories(unity PUBLIC Unity/src)
#    add_library(unity_fixture STATIC Unity/extras/fixture/src/unity_fixture.c)
#    target_include_directories(unity_fixture PUBLIC Unity/extras/fixture/src)

# or use included CMakeLists.txt
    set(UNITY_EXTENSION_FIXTURE yes)

    add_subdirectory(unity)
```

**Features**:

- [x] general usage of one test executable / file
- [x] `setUp` and `tearDown` functions run before each test; context shared via global variables
- [x] `unity_fixtures` can handle test groups; enables collecting tests from multiple files, and group-specific setup/teardown functions
- [x] large variety of asserts, including _ARRAY, _EACH_EQUAL, comparisons and float/double types
- [x] all asserts come with _MESSAGE variant to display custom message
- [x]

**Output**:

![aaa]()

**Issues**:

### Template

**Websites**:

- home: <url>
- repo: <url>

**Maintainers**:

**Activity**:

**Popularity**:

**Documentation**:

**Ease of use**:

**CMake integration**:

**Features**:

- [ ] feature

**Output**:

![image]()

**Issues**:
