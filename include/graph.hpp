#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <cstddef>
#include <limits>

class Graph {
public:
    explicit Graph(size_t node_count);
    void add_edge(size_t src, size_t dest, int weight);
    const std::vector<std::vector<int>>& get_edges() const;
    size_t node_count() const;

private:
    size_t nodes_;
    std::vector<std::vector<int>> edges_;
};

#endif // GRAPH_HPP
