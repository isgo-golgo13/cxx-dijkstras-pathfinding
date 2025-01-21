#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph.hpp"
#include <vector>

// Perform Dijkstra's algorithm
std::vector<int> dijkstra(const Graph& graph, size_t source);

#endif // DIJKSTRA_HPP
