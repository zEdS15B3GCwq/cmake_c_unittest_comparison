# cmake_c_unittest_comparison
Comparison of C language unit testing frameworks with CMake (CUnit, Unity, cmocka etc)

### Purpose

I'm on the search for a simple unit testing framework for pure C. Some frameworks are more popular and are mentioned in many forum discussions, such as Unity / Ceedling, CUnit, cmocka, but there are plenty other less known ones that could be just as good. C++ frameworks are excluded (google test, boost test, cppunit and alike) even if they're supposed to work well with C. I don't want to bother with mixed code.

As I explore different options, I check a few points about them, such as how actively they're maintained, number of maintainers, how easy they're to integrate into a simple CMake / CTest project, how informative the output is and so on. I'm not going to waste a lot of time on each framewok - it's going to be mostly first-impressions level, so don't expect deep insights. First I need to reduce the list to a few best options, that's what these notes are for.

### Progress

This is obviously a work in progress.

* Frameworks I've tried:

  this list is going to grow

* List of frameworks I'm going to try (tentative, at best)

  1. [CUnit](https://cunity.gitlab.io/cunit/) (CUnity fork)
  2. [Unity](http://www.throwtheswitch.org/unity)
  3. [GLib testing framework](https://docs.gtk.org/glib/testing.html)
  4. [cmocka](https://cmocka.org/)
  5. [µnit (munit)](https://nemequ.github.io/munit/)
  6. [ctest](https://github.com/bvdberg/ctest) (not the one included in CMake)
  7. [Cgreen](https://github.com/cgreen-devs/cgreen)
  8. [Criterion](https://github.com/Snaipe/Criterion/)
  9. [tau](https://github.com/jasmcaus/tau/)
  10. [libcester](https://github.com/exoticlibraries/libcester)
