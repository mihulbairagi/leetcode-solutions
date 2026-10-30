import heapq

class Solution:
    def shortestPath(self, n: int, edges: list[list[int]], labels: str, k: int) -> int:
        adj = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((v, w))

        dist = [[float('inf')] * (k + 1) for _ in range(n)]

        pq = [(0, 0, 1)] 
        dist[0][1] = 0

        min_final_cost = float('inf')

        while pq:
            d, u, u_count = heapq.heappop(pq)

            if d > dist[u][u_count]:
                continue

            if u == n - 1:
                min_final_cost = min(min_final_cost, d)
            
            u_char = labels[u]

            for v, weight in adj[u]:
                v_char = labels[v]

                if v_char == u_char:
                    v_count = u_count + 1
                else:
                    v_count = 1
                
                if v_count <= k:
                    if d + weight < dist[v][v_count]:
                        dist[v][v_count] = d + weight
                        heapq.heappush(pq, (d + weight, v, v_count))
        
        return int(min_final_cost) if min_final_cost != float('inf') else -1