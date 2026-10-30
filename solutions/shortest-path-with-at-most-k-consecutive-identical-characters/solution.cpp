#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <limits>
#include <algorithm>

class Solution {
public:
    int shortestPath(int n, std::vector<std::vector<int>>& edges, std::string labels, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        std::vector<std::vector<long long>> dist(n, std::vector<long long>(k + 1, std::numeric_limits<long long>::max()));

        std::priority_queue<std::tuple<long long, int, int>, 
                            std::vector<std::tuple<long long, int, int>>, 
                            std::greater<std::tuple<long long, int, int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        long long minFinalCost = std::numeric_limits<long long>::max();

        while (!pq.empty()) {
            auto [d, u, u_count] = pq.top();
            pq.pop();

            if (d > dist[u][u_count]) {
                continue;
            }

            if (u == n - 1) {
                minFinalCost = std::min(minFinalCost, d);
            }

            char u_char = labels[u];

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                char v_char = labels[v];

                int v_count;
                if (v_char == u_char) {
                    v_count = u_count + 1;
                } else {
                    v_count = 1;
                }

                if (v_count <= k) {
                    if (d + weight < dist[v][v_count]) {
                        dist[v][v_count] = d + weight;
                        pq.push({d + weight, v, v_count});
                    }
                }
            }
        }
        
        return (minFinalCost == std::numeric_limits<long long>::max()) ? -1 : static_cast<int>(minFinalCost);
    }
};