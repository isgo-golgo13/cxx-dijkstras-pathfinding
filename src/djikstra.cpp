#include "dijkstra.hpp"
#include <queue>
#include <vector>
#include <atomic>
#include <limits>
#include <thread>
#include <mutex>

std::vector<int> dijkstra(const Graph& graph, size_t source) {
    const auto& edges = graph.get_edges();
    const size_t n = graph.node_count();
    std::vector<std::atomic<int>> distances(n);
    std::vector<std::atomic<bool>> visited(n);

    for (size_t i = 0; i < n; ++i) {
        distances[i].store(std::numeric_limits<int>::max());
        visited[i].store(false);
    }
    distances[source].store(0);

    auto compare = [&distances](size_t lhs, size_t rhs) {
        return distances[lhs].load() > distances[rhs].load();
    };
    std::priority_queue<size_t, std::vector<size_t>, decltype(compare)> pq(compare);

    pq.push(source);

    std::mutex pq_mutex;

    auto process_node = [&](size_t node) {
        visited[node].store(true);
        for (size_t neighbor = 0; neighbor < n; ++neighbor) {
            int edge_weight = edges[node][neighbor];
            if (edge_weight != -1 && !visited[neighbor].load()) {
                int new_distance = distances[node].load() + edge_weight;
                int current_distance = distances[neighbor].load();
                if (new_distance < current_distance) {
                    distances[neighbor].store(new_distance);
                    {
                        std::lock_guard<std::mutex> lock(pq_mutex);
                        pq.push(neighbor);
                    }
                }
            }
        }
    };

    std::vector<std::thread> threads;
    while (!pq.empty()) {
        size_t node;
        {
            std::lock_guard<std::mutex> lock(pq_mutex);
            if (pq.empty()) break;
            node = pq.top();
            pq.pop();
        }
        if (!visited[node].load()) {
            threads.emplace_back(process_node, node);
        }
    }

    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    std::vector<int> result(n);
    for (size_t i = 0; i < n; ++i) {
        result[i] = distances[i].load();
    }
    return result;
}
