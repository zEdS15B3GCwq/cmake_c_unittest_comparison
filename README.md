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

**Activity and Maintainers**: single developer; repo inactive; besides a recent version bump, last commit was >1 year ago.

**Popularity**: mentioned in multiple forum discussions; it's a well known and mature library, I guess.

**Documentation**: pre-fork CUnit has detailed docs; the new fork's docs don't go much beyond simple usage with the new CUnitCI API.

**Ease of use**: new CUnitCI macros are easy to learn and use for simple use cases; pre-fork API can do much more but is quite complex in return.

**CMake integration**: very easy, project comes with own CMakeFile.txt; no special build dependencies

```CMake
    set(CUNIT_DISABLE_EXAMPLES yes)
    set(CUNIT_DISABLE_TESTS yes)

    add_subdirectory(cunit/CUnit)
```

**General Features**: sufficient; fairly good organisation of tests (suites, registry), not so versatile in terms of smart asserts

- [x] tests can be organised into suites, which can added to a registry to be run together
- [x] each suite can have their own suite-level and pre-test setup / teardown functions
- [x] test context shared via global variables
- [x] easy to use with one executable / test code file  (see [single_suite](tests/cunit/single_suite/) example)
- [x] multiple tests / suites can be linked into one executable (though this isn't well documented, see [multi_suite](tests/cunit/multi_suite/) example);
- [ ] no mocking
- [ ] no individual test timing

**Asserts**:

- [x] distinguishes between fatal and non-fatal assertions, allowing multiple asserts in one test (however, only the last failure is reported on the command line - see comments on output)
- [ ] limited [selection of asserts](https://cunit.sourceforge.net/doc/writing_tests.html)
- [ ] no array-capable assertions

ASSERT, TRUE/FALSE, PASS/FAIL, [ - | PTR | STRING | NSTRING | DOUBLE ] [NOT] EQUAL

all (except PASS) have _FATAL and non-fatal variants

**Output**: terminal + JUnit XML

- [x] JUnit XML output
- [x] show executed code for failed tests
- [ ] cannot include custom messages in failed test output (unless using a trick like `condition && "message"` in assert)
- [ ] variable values not shown in failed tests

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

**Activity and Maintainers**: 100+ contributors, though only 1 contributor has committed code in 2023 (as of April 2023). The last bugfix release was in 2021 Jan; last feature release in 2019 Oct; main maintainer [claims](https://groups.google.com/g/throwtheswitch/c/JKg9GgdeYHw) that development is active and going mostly in the direction of Ceedling and such, and the forums are pretty active too.

**Popularity**: many mentions, seems to be popular

**Documentation**: the docs describe a simple use case and that part is easy to understand, easy to implement and integrate. However, there'a lot beyond that that's hidden in the code and examples. For example, the only references on `unity_fixtures` are comments in the source and the [2nd example](https://github.com/ThrowTheSwitch/Unity/tree/master/examples/example_2). While it may not meant to be the main way to use Unity, it should be better documented if it exists. Also, some configuration options that are documented and are supposed to change the output (e.g. `UNITY_OUTPUT_FOR_ECLIPSE`) don't seem to be doing anything.

**Ease of use**: easy; there's a "general" mode that suits 1 exe / code file, and a "fixture" mode with test group functionality; both modes are fairly simple to use... with exceptions in the latter due to lack of docs. On the other hand, a lot of additional functionality is provided by _Ruby_ scripts (e.g. test generators), which is unfortunate as I don't want to use _Ruby_.

**CMake integration**: the project includes `CMakeLists.txt` scripts as well, and there are some instructions on how to include it as a simple source file.

```CMake
    set(UNITY_EXTENSION_FIXTURE yes CACHE BOOL "compile unity with fixtures extension")

    add_subdirectory(unity)
```

Got a lot of warnings, though, when I actually included `unit_fixture` in the build.

**General Features**:

- [x] general usage of one test executable / file
- [x] `setUp` and `tearDown` functions run before each test; context shared via global variables
- [x] `unity_fixtures` can handle test groups; enables collecting tests from multiple files, and group-specific setup/teardown functions
- [ ] no mocking, but CMock from same developer is recommended; uses Ruby scripts, though

**Asserts**: [list](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)

- [x] large variety of type-specific asserts (TRUE/FALSE, NULL, INT*, UINT*, HEX*, FLOAT, DOUBLE)
- [x] `_ARRAY` and `_EACH_EQUAL` variants to compare arrays
- [x] `_MESSAGE` variants to display custom message
- [x] [NOT] WITHIN, LESS / GREATER, NEG variants for bounds checking
- [x] BITS for bitmasks

**Output**:

- [ ] only command-line output
- [ ] doesn't show executed code for failed tests
- [x] can include custom messages in output (`_MESSAGE` variants)
- [x] variable values shown in specific tests
- [ ] inconsistent output between `unity` and `unity_fixture`

![Unity test result output](images/results_unity.png)

In my opinion, output from Unity is in some ways better, in other ways less informative than CUnit's. It's good that custom messages can be included, and that, for specific tests, actual values are shown (i.e. `2` instead of `identity (a)`), however, these outputs lack context without at least showing the executed code inside the assert. For example, `Expected TRUE was FALSE` (see `multi_suite_a/test_a_identity_should_fail`) is useless information unless a custom message is included or one looks up the failing source code. Having to add meaningful custom messages to _each_ test isn't ideal. At least showing the code would help a bit. This is actually possible with custom macros that add a text version of the code (`#code`) to the custom message (see `TEST_ASSERT_EQUAL_INT_M` and `TEST_ASSERT_EQUAL_INT_MESSAGE_M` in `single_suite.c`) but, again, this requires extra work. Related Ruby scripts might offer better output, but I don't want to use Ruby.

I also find CUnit's output easier to read. For example, it only shows the full path to the source file for failing tests. Passing tests are only listed by test name. And as mentioned, the XML output from CUnit includes all the failing asserts within a test, so it's possible (even if not always practical) to have several non-fatal asserts in one test. That doesn't work with Unity (see `..._again` tests to actually get those tests to execute).

Furthermore, the output is not consistent between `unity` and `unity_fixture`. The latter only listed failing tests; passing tests were not shown (e.g. `test_a_identity_should_pass`), whereas the former listed the passing test as well. Maybe there's a setting somewhere? I didn't see that in the docs.

### GLib

**Websites**:

- home: <https://docs.gtk.org/glib/testing.html>
- repo: <https://gitlab.gnome.org/GNOME/glib>

**Maintainers**:

**Activity**:

**Popularity**:

**Documentation**:

**Ease of use**:

**CMake integration**:

**General Features**:

only string array comparison assert but can implement others using non-fatal asserts in loop
optional non-fatal failures
per-test setup/teardown with automatically allocated custom struct
tests can optionally receive fixture and pointer to user data
output duplicates errors on stdout and stderr, can be too verbose; it may not be possible to redirect one when using CTest
tests organised hierarchically with path string (e.g. `/suite_1/test_1`), easy to group
has _trap_ functionality for running tests that may not return in another process
multiple ways of adding tests with multiple levels of detail defined, practical option, can be combined easily
needs glib (on windows, easiest for me was installing gstreamer)

- [ ] feature

**Asserts**:

**Output**:

![image]()

**Issues**:
