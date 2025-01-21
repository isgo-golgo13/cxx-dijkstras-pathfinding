cmake_minimum_required(VERSION 3.20)
project(DijkstraCpp20 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dijkstra
    dijkstra.svc.cpp
    graph.cpp
    dijkstra.cpp
)

target_compile_options(dijkstra PRIVATE -Wall -Wextra -Wpedantic -O2)
