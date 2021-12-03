cmake_minimum_required(VERSION 3.1) # Mandatory.
project( first_project ) # Mandatory.
set( CMAKE_CXX_STANDARD 17) # Use c++17.
# tell cmake where to look for *.hpp, *.h files
include_directories(include/project_name/)
# create library "libtools"
add_library(tools src/project_name/tools.cpp) # creates libtools.a
 # add executable main
add_executable(main src/project_name/main.cpp) # main.o
# tell the linker to bind these objects together
target_link_libraries(main tools) # ./main