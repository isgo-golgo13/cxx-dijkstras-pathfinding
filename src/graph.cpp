#include "graph.hpp"
#include <stdexcept>

Graph::Graph(size_t node_count)
    : nodes_(node_count), edges_(node_count, std::vector<int>(node_count, -1)) {}

void Graph::add_edge(size_t src, size_t dest, int weight) {
    if (src >= nodes_ || dest >= nodes_) {
        throw std::out_of_range("Edge indices out of range");
    }
    edges_[src][dest] = weight;
}

const std::vector<std::vector<int>>& Graph::get_edges() const {
    return edges_;
}

size_t Graph::node_count() const {
    return nodes_;
}
