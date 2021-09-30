cmake_minimum_required (VERSION 3.14 FATAL_ERROR)
set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-11")

# Compiler flags
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -Wextra -g -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-DNEDEBUG -O3")

project(FPL_cpppractice)

# Target names
set(exe_name "best_season")
set(exe_utest_name "${exe_name}_unit_tests")
set(exe_lib "best_season_obj")

# Main executable (for now)
add_executable(${exe_name} main.cpp uf_io.cpp player.cpp decisionmaker.cpp)
# Communicate source directory to code
target_compile_definitions(${exe_name} PRIVATE src_dir="${CMAKE_SOURCE_DIR}")
# Make object files accessible (for sake of gtest code)
add_library(${exe_lib} OBJECT uf_io.cpp player.cpp decisionmaker.cpp)
target_compile_definitions(${exe_lib} PRIVATE src_dir="${CMAKE_SOURCE_DIR}")

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
