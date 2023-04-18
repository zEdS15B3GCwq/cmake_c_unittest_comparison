# C Unit Test Comparison with CMake

Comparison of C language unit testing frameworks with CMake (CUnit, Unity, cmocka etc)

## 1. Purpose

I'm on the search for a simple unit testing framework for pure C. Some frameworks are more popular and are mentioned in many forum discussions, such as Unity / Ceedling, CUnit, cmocka, but there are plenty other less known ones that could be just as good. I'm looking for one that has informative output, is easy to build / integrate, is easy to learn (no lengthy documentation), and is actively maintained and can be expected to be around for a while (good history, adaptation, number of maintainers). It's all going to be quite superficial, first-impressions level, because I don't want to waste a lot of time getting to know a complex system.

C++ frameworks are excluded (google test, boost test, cppunit and alike) even if they're supposed to work well with C. No mixed code for me.

This is, obviously, a work in progress.

## 2. List of Candidates

1. [Unity](http://www.throwtheswitch.org/unity)
2. [GLib testing framework](https://docs.gtk.org/glib/testing.html)
3. [cmocka](https://cmocka.org/)
4. [µnit (munit)](https://nemequ.github.io/munit/)
5. [ctest](https://github.com/bvdberg/ctest) (not the one included in CMake)
6. [Cgreen](https://github.com/cgreen-devs/cgreen)
7. [Criterion](https://github.com/Snaipe/Criterion/)
8. [tau](https://github.com/jasmcaus/tau/)
9. [libcester](https://github.com/exoticlibraries/libcester)

## 3. Impressions

### 3.1 Cunit (Cunity fork)

Websites:

- fork homepage: <https://cunity.gitlab.io/cunit/>
- fork repo: <https://gitlab.com/cunity/cunit/-/tree/master/>
- original home: <https://cunit.sourceforge.net/example.html>

Maintainers: single developer

Activity: inactive; besides a recent version bump, last commit was >1 year ago

Maturity: long existing, mature code

Documentation: not much, but enough for the simplest use case; beyond that, one needs to look at the code.

CMake integration: very easy, project comes with own CMakeFile.txt; no special build dependencies

```CMake
    set(CUNIT_DISABLE_EXAMPLES yes)
    set(CUNIT_DISABLE_TESTS yes)

    add_subdirectory(cunit/CUnit)
```

Features: sufficient

- suite and pre-test setup / teardown functions
- test context shared via global variables
- easy to use with one executable / test code file  (see [single_suite](tests/cunit/single_suite/) example)
- multiple tests / suites can be linked into one executable but this case isn't well documented (see [multi_suite](tests/cunit/multi_suite/) example)

Output: terminal + XML

![CUnit test result output](images/results_cunit.png)
