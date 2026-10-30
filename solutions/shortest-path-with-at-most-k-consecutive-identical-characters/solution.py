import heapq

class Solution:
    def shortestPath(self, n: int, edges: list[list[int]], labels: str, k: int) -> int:
        adj = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((v, w))

        dist = [[([float('inf')] * 26) for _ in range(k + 1)] for _ in range(n)]
        
        pq = []

        start_char_index = ord(labels[0]) - ord('a')
        dist[0][0][start_char_index] = 0
        heapq.heappush(pq, (0, 0, 0, start_char_index)) # (cost, node, consecutive_count, last_char_index)

        while pq:
            cost, u, consecutive, last_char_index = heapq.heappop(pq)

            if cost > dist[u][consecutive][last_char_index]:
                continue
            
            if u == n - 1:
                return cost

            for v, weight in adj[u]:
                current_char_index = ord(labels[v]) - ord('a')
                
                new_consecutive = 0
                if current_char_index == last_char_index:
                    new_consecutive = consecutive + 1
                else:
                    new_consecutive = 0

                if new_consecutive <= k:
                    new_cost = cost + weight
                    if new_cost < dist[v][new_consecutive][current_char_index]:
                        dist[v][new_consecutive][current_char_index] = new_cost
                        heapq.heappush(pq, (new_cost, v, new_consecutive, current_char_index))
        
        return -1
