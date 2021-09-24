cmake_minimum_required(VERSION 3.10)
project(FPL_cpppractice)
set(CMAKE_CXX_COMPILER "g++-11")

add_executable(best_season driver.cpp player.cpp)

if(ENABLE_TESTS)
  enable_testing()
  include(CTest)
  add_subdirectory(tests)
endif()
