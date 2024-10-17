cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EXPORT_COMPILE_COMMANDS ON)

project(cryptoms)

set(CMAKE_CXX_FLAGS "-Wall -Werror")

find_package(ZLIB)
find_package(Boost REQUIRED)

add_definitions(-DVERSION="STP version")

include_directories(mtl)
include_directories(MTRand)

add_executable(cryptominisat
    Logger.cpp
    Solver.cpp
    Gaussian.cpp
    PackedRow.cpp
    XorFinder.cpp
    MatrixFinder.cpp
    VarReplacer.cpp
    FindUndef.cpp
    ClauseCleaner.cpp
    RestartTypeChooser.cpp
    FailedVarSearcher.cpp
    PartFinder.cpp
    Subsumer.cpp
    PartHandler.cpp
    XorSubsumer.cpp
    StateSaver.cpp
    ClauseAllocator.cpp
    UselessBinRemover.cpp
    OnlyNonLearntBins.cpp
    Main.cpp
)

target_link_libraries(cryptominisat
    ZLIB::ZLIB
    Boost::boost
    mtl
    MTRand
)


