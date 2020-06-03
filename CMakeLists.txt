cmake_minimum_required(VERSION 3.17)

set(This Example)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE on)

enable_testing()

add_subdirectory(
    googletest
)

set(Headers
    Example.hpp
)

set(Source
    Example.cpp 
)

add_library(${This} STATIC ${Source} ${Headers})

add_subdirectory(test)