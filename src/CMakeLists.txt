cmake_minimum_required (VERSION 3.14 FATAL_ERROR)
set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-11")
project(FPL_cpppractice)

# Target names
set(exe_name "best_season")
set(exe_utest_name "${exe_name}_unit_tests")

# Main executable (for now)
add_executable(${exe_name} driver.cpp player.cpp)

option(ENABLE_UNIT_TESTS "Enable unit testing" ON)
option(ENABLE_TESTS "Enable regression testing" OFF)

if(ENABLE_UNIT_TESTS)
  add_executable(${exe_utest_name})
  add_subdirectory("googletest")
  add_subdirectory("unit_tests")
endif()

if(ENABLE_TESTS)
  enable_testing()
  include(CTest)
  add_subdirectory("tests")
endif()
