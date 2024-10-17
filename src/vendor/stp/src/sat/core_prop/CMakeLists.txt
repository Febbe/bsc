
#include $(MROOT)/mtl/template.mk

file(GLOB_RECURSE sources "*.cpp")

add_library(core_prop STATIC ${sources})
target_link_libraries(core_prop PUBLIC mtl utils)
target_include_directories(core_prop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
