cmake_minimum_required(VERSION 3.1) # Mandatory.
#gtest
# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
# )
project( first_project ) # Mandatory.
set( CMAKE_CXX_STANDARD 17) # Use c++17.
# tell cmake where to look for *.hpp, *.h files
include_directories(include/project_name/)
# create library "libtools"
add_library(tools src/project_name/tools.cpp) # creates libtools.a
 # add executable main
add_executable(turtleworld src/project_name/main.cpp) # main.o
# tell the linker to bind these objects together
target_link_libraries(main tools ) # ./main
#testing 
# enable_testing()
# add_executable(
#   tests/hello_test
#   hello_test.cpp
# )
# target_link_libraries(
#   hello_test
#   gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(hello_test)