cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# COMPDIR=$(TOP)/src/comp
# Todo: ./gen_version_h $(COMPDIR)/BuildVersion.hs > version.h
set(bluesim_version 9.9.9 CACHE STRING "Bluesim version")

project(Bluesim 
   LANGUAGES CXX
   VERSION ${bluesim_version})

set(Bluesim_CXX_FLAGS_POSIX
    -Wpointer-arith
    -Wshadow
    -Wcast-qual
    -Wno-unused-parameter
    -g
    -D_ISOC17_SOURCE
    -D_FILE_OFFSET_BITS=64
    -fno-rtti
    -fPIC
)

set(Bluesim_C_FLAGS_POSIX
    -Wall 
    -Wextra 
    -Werror
    -Wmissing-prototypes
    -Wstrict-prototypes
    -Wpointer-arith
    -Wshadow
    -Wcast-qual
    -Wno-unused-parameter
    -g
    -std=c17
    -D_FILE_OFFSET_BITS=64
    -fPIC
)

# These get copied to the inst/lib/Bluesim area
# Todo place those into include/Bluesim
set(Bluesim_public_headers 
    bluesim_kernel_api.h
    bluesim_types.h
    bluesim_primitives.h
    bluesim_systemc.h 
    bluesim_probes.h 
    bs_wide_data.h 
    bs_prim_ops.h 
    bs_prim_mod_reg.h 
    bs_prim_mod_wire.h 
    bs_prim_mod_probe.h
    bs_prim_mod_fifo.h 
    bs_prim_mod_regfile.h 
    bs_prim_mod_bram.h
    bs_prim_mod_counter.h
    bs_prim_mod_clockgen.h
    bs_prim_mod_synchronizers.h
    bs_prim_mod_gatedclock.h
    bs_prim_mod_clockmux.h
    bs_prim_mod_resets.h
    bs_reset.h
    bs_symbol.h
    bs_system_tasks.h
    bs_mem_defines.h 
    bs_mem_file.h 
    bs_range_tracker.h
    bs_vcd.h bs_module.h bs_target.h
    bs_model.h
)

#pkg_check_modules(GLIB2 IMPORTED_TARGET "glib-2.0>=${GLIB_REQUIRED}" "gobject-2.0>=${GLIB_REQUIRED}" "gio-2.0>=${GLIB_REQUIRED}")
#find_package(GLIB 2.20)
# C,CXX: -D_DEFAULT_SOURCE
# else, C,CXX: -D_SVID_SOURCE
#DEBUG C,CXX FLAG: -UUSE_ENTER

set(libbsprim_sources 
    prim_ops.cxx
    wide_data.cxx
    mem_alloc.cxx
    target.cxx
    prim_mod_reg.cxx
    prim_mod_wire.cxx
    prim_mod_probe.cxx
    prim_mod_fifo.cxx
    prim_mod_regfile.cxx
    prim_mod_bram.cxx
    prim_mod_counter.cxx
    prim_mod_clockgen.cxx
    prim_mod_synchronizers.cxx
    prim_mod_gatedclock.cxx
    prim_mod_resets.cxx
    dollar_display.cxx
    dollar_dumpvars.cxx
    dollar_plusargs.cxx
    dollar_stop_finish.cxx
    dollar_time.cxx
    mem_file.cxx
    module.cxx
    portability.cxx
    rand32.cxx
)

configure_file(version.h.in version.h)
# Description of library of Bluesim primitives
add_library(libbsprim STATIC ${libbsprim_sources})

add_library(libbskernel STATIC
kernel.cxx
event_queue.cxx
priority.cxx
symbol.cxx
reset.cxx
plusargs.cxx
vcd.cxx
portability.cxx
)

target_include_directories(libbskernel PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_sources(libbskernel PUBLIC ${Bluesim_public_headers})
# Static check of the header files before releasing them.
set_property(TARGET libbskernel PROPERTY VERIFY_INTERFACE_HEADER_SETS ON)

install(TARGETS libbsprim libbskernel
    DESTINATION lib/Bluesim
)

install(FILES ${Bluesim_public_headers}
    DESTINATION lib/Bluesim
)
# These ld export maps get copies to the inst/lib/Bluesim area
install(FILES bs_elf_export_map.txt bs_mach-o_export_map.txt
    DESTINATION lib/Bluesim
)
