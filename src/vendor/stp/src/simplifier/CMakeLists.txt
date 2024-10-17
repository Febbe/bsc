cmake_minimum_required(VERSION 3.15)

project(simplifier)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE sources "*.cpp" "constantBitP/*.cpp")

add_library(simplifier STATIC ${sources})
target_link_libraries(simplifier PUBLIC boost STPManager boost AST sat extlib-constbv)
