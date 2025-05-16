#include "graph.hpp"
#include <stack>
#include <set>
#include <queue>
#include <unordered_map>
#include <functional>
#include <iostream>

namespace Graph {
    void WeightedGraph::add_vertex(int const id) {
        if (adjacency_list.find(id) == adjacency_list.end()) {
            adjacency_list[id] = {};
        }
    }

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight) {
        add_vertex(from);
        add_vertex(to);
        adjacency_list[from].push_back({to, weight});
    }

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight) {
        add_directed_edge(from, to, weight);
        add_directed_edge(to, from, weight);
    }

    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix) {
        WeightedGraph g;
        int n = static_cast<int>(adjacency_matrix.size());
        for (int i = 0; i < n; ++i) {
            g.add_vertex(i);
            for (int j = 0; j < static_cast<int>(adjacency_matrix[i].size()); ++j) {
                if (adjacency_matrix[i][j] != 0) {
                    g.add_directed_edge(i, j, adjacency_matrix[i][j]);
                }
            }
        }
        return g;
    }

    void WeightedGraph::print_DFS(int const start) const {
        std::set<int> visited;
        std::stack<int> stack;
        stack.push(start);
        while (!stack.empty()) {
            int node = stack.top(); stack.pop();
            if (visited.find(node) == visited.end()) {
                std::cout << node << " ";
                visited.insert(node);
                for (auto it = adjacency_list.at(node).rbegin(); it != adjacency_list.at(node).rend(); ++it) {
                    if (visited.find(it->to) == visited.end()) {
                        stack.push(it->to);
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    void WeightedGraph::print_BFS(int const start) const {
        std::set<int> visited;
        std::queue<int> queue;
        queue.push(start);
        visited.insert(start);
        while (!queue.empty()) {
            int node = queue.front(); queue.pop();
            std::cout << node << " ";
            for (const auto& edge : adjacency_list.at(node)) {
                if (visited.find(edge.to) == visited.end()) {
                    queue.push(edge.to);
                    visited.insert(edge.to);
                }
            }
        }
        std::cout << std::endl;
    }

    void WeightedGraph::DFS(int const start, std::function<void(int const)> const& callback) const {
        std::set<int> visited;
        std::stack<int> stack;
        stack.push(start);
        while (!stack.empty()) {
            int node = stack.top(); stack.pop();
            if (visited.find(node) == visited.end()) {
                callback(node);
                visited.insert(node);
                for (auto it = adjacency_list.at(node).rbegin(); it != adjacency_list.at(node).rend(); ++it) {
                    if (visited.find(it->to) == visited.end()) {
                        stack.push(it->to);
                    }
                }
            }
        }
    }

    bool WeightedGraph::operator==(WeightedGraph const& other) const {
        return adjacency_list == other.adjacency_list;
    }

    bool WeightedGraph::operator!=(WeightedGraph const& other) const {
        return !(*this == other);
    }

    bool WeightedGraphEdge::operator==(WeightedGraphEdge const& other) const {
        return to == other.to && weight == other.weight;
    }

    bool WeightedGraphEdge::operator!=(WeightedGraphEdge const& other) const {
        return !(*this == other);
    }

    std::unordered_map<int, std::pair<float, int>> dijkstra(WeightedGraph const& graph, int const& start, int const end) {
        std::unordered_map<int, std::pair<float, int>> distances;
        std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> to_visit;
        to_visit.push({0.0f, start});
        distances[start] = {0.0f, -1};
        while (!to_visit.empty()) {
            auto [dist, node] = to_visit.top();
            to_visit.pop();
            if (node == end) break;
            for (auto const& edge : graph.adjacency_list.at(node)) {
                float new_dist = dist + edge.weight;
                auto it = distances.find(edge.to);
                if (it == distances.end() || new_dist < it->second.first) {
                    distances[edge.to] = {new_dist, node};
                    to_visit.push({new_dist, edge.to});
                }
            }
        }
        return distances;
    }
}
