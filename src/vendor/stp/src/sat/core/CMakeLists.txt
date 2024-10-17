cmake_minimum_required(VERSION 3.15)

file(GLOB_RECURSE sources "*.cpp")

add_library(core STATIC ${sources})
target_link_libraries(core PUBLIC mtl util)