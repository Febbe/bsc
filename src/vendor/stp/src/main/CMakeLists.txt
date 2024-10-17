cmake_minimum_required(VERSION 3.15)

set(sources
	main.cpp
	Globals.cpp
)

add_library(main STATIC ${sources})
