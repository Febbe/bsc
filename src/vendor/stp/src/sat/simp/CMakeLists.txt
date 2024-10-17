cmake_minimum_required(VERSION 3.15)

project(simp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE sources "*.cpp")

add_library(simp STATIC ${sources})
target_link_libraries(simp PUBLIC mtl utils core)
