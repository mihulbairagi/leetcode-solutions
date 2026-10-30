#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<vector<vector<int>>> dist(n, vector<vector<int>>(k + 1, vector<int>(26, numeric_limits<int>::max())));

        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;

        int startCharIndex = labels[0] - 'a';
        dist[0][0][startCharIndex] = 0;
        pq.push({0, 0, 0, startCharIndex}); // {cost, node, consecutive_count, last_char_index}

        while (!pq.empty()) {
            auto [cost, u, consecutive, lastCharIndex] = pq.top();
            pq.pop();

            if (cost > dist[u][consecutive][lastCharIndex]) {
                continue;
            }
            
            if (u == n - 1) {
                return cost;
            }

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                int currentCharIndex = labels[v] - 'a';

                int newConsecutive = 0;
                if (currentCharIndex == lastCharIndex) {
                    newConsecutive = consecutive + 1;
                } else {
                    newConsecutive = 0;
                }

                if (newConsecutive <= k) {
                    int newCost = cost + weight;
                    if (newCost < dist[v][newConsecutive][currentCharIndex]) {
                        dist[v][newConsecutive][currentCharIndex] = newCost;
                        pq.push({newCost, v, newConsecutive, currentCharIndex});
                    }
                }
            }
        }

        return -1;
    }
};
