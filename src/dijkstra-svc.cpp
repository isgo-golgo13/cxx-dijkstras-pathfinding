#include "graph.hpp"
#include "dijkstra.hpp"
#include <iostream>
#include <vector>

int main() {
    Graph graph(5);
    graph.add_edge(0, 1, 10);
    graph.add_edge(0, 2, 3);
    graph.add_edge(1, 2, 1);
    graph.add_edge(1, 3, 2);
    graph.add_edge(2, 1, 4);
    graph.add_edge(2, 3, 8);
    graph.add_edge(2, 4, 2);
    graph.add_edge(3, 4, 7);
    graph.add_edge(4, 3, 9);

    std::vector<int> distances = dijkstra(graph, 0);

    std::cout << "Shortest distances from node 0:\n";
    for (size_t i = 0; i < distances.size(); ++i) {
        std::cout << "Node " << i << ": " << distances[i] << '\n';
    }

    return 0;
}
