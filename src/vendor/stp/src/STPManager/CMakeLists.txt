cmake_minimum_required(VERSION 3.15)

project(STPManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE sources "*.cpp")

add_library(stpmgr STATIC ${sources})
target_link_libraries(stpmgr PUBLIC STPManager boost AST sat simplifier extlib-abc)