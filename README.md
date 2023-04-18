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

**Maturity**: long existing, mature code

**Popularity**: mentioned in multiple forum discussions; it's well known, I guess.

**Documentation**: the new fork has some documentation for a simple case using the new CUnitCI API; there's documentation on the old website for the traditional API, but that requires a longer learning process.

**CMake integration**: very easy, project comes with own CMakeFile.txt; no special build dependencies

```CMake
    set(CUNIT_DISABLE_EXAMPLES yes)
    set(CUNIT_DISABLE_TESTS yes)

    add_subdirectory(cunit/CUnit)
```

**Features**: sufficient

- [x] suite and pre-test setup / teardown functions
- [x] test context shared via global variables
- [x] easy to use with one executable / test code file  (see [single_suite](tests/cunit/single_suite/) example)
- [x] multiple tests / suites can be linked into one executable but this case isn't well documented (see [multi_suite](tests/cunit/multi_suite/) example)
- [x] failed tests show executed code
- [ ] cannot include custom messages in failed test output
- [ ] variable values not shown in failed tests
- [ ] no direct support for mocking

**Output**: terminal + XML

![CUnit test result output](images/results_cunit.png)

**Issues**:

In case of multiple failing assertions in one test, only the last one's code is reported to the command line!:O See: only `CU_ASSERT_EQUAL( 99, identity( a ) )` is shown in [single_suite/test_identity_should_fail](tests/cunit/single_suite/single_suite.c). This means that it's better to use _FATAL asserts or single asserts per test.

### 3.2 Unity

**Websites**:

- home: <http://www.throwtheswitch.org/unity>
- repo: <https://github.com/ThrowTheSwitch/Unity>

**Maintainers**:

**Activity**:

**Maturity**:

**Popularity**:

**Documentation**:

**CMake integration**:

**Features**:

- [ ] aaa

**Output**:

![aaa]()

**Issues**:

### Template

**Websites**:

- home: <url>
- repo: <url>

**Maintainers**:

**Activity**:

**Maturity**:

**Popularity**:

**Documentation**:

**CMake integration**:

**Features**:

- [ ] feature

**Output**:

![image]()

**Issues**:
