cmake_minimum_required(VERSION 3.15)

file(GLOB_RECURSE sources "*.cc")

add_library(utils STATIC ${sources})
target_link_libraries(utils PUBLIC mtl)