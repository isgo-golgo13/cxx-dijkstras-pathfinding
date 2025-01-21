cmake_minimum_required(VERSION 3.20)
project(DijkstraCpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify source files
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

set(SOURCES
    ${SRC_DIR}/dijkstra-svc.cpp
    ${SRC_DIR}/dijkstra.cpp
    ${SRC_DIR}/graph.cpp
)

# Add the executable
add_executable(dijkstra ${SOURCES})

# Include directories
target_include_directories(dijkstra PRIVATE ${INCLUDE_DIR})

# Compiler options
target_compile_options(dijkstra PRIVATE -Wall -Wextra -pedantic -O2)
