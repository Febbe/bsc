cmake_minimum_required(VERSION 3.15)

file(GLOB_RECURSE headers "*.h")

add_library(mtl INTERFACE)
target_include_directories(mtl INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(mtl INTERFACE ${headers})
