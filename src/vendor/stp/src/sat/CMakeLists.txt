cmake_minimum_required(VERSION 3.15)

project(minisat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EXPORT_COMPILE_COMMANDS ON)

file(GLOB sources "*.cpp")

add_subdirectory(core_prop)
add_subdirectory(core)
add_subdirectory(simp)
add_subdirectory(utils)
add_subdirectory(cryptominisat2)

add_library(minisat STATIC ${sources})
target_link_libraries(minisat PUBLIC STPManager boost AST sat simplifier extlib-abc)
