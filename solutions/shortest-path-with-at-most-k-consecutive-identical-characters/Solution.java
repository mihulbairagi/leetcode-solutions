import java.util.*;
class Solution {
    public int shortestPath(int n, int[][] edges, String labels, int k) {
        List<int[]>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].add(new int[]{v, w});
        }
        long[][] dist = new long[n][k + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], Long.MAX_VALUE);
        }
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
        dist[0][1] = 0;
        pq.offer(new long[]{0, 0, 1});
        long minFinalCost = Long.MAX_VALUE;
        while (!pq.isEmpty()) {
            long[] current = pq.poll();
            long d = current[0];
            int u = (int) current[1];
            int uCount = (int) current[2];
            if (d > dist[u][uCount]) {
                continue;
            }
            if (u == n - 1) {
                minFinalCost = Math.min(minFinalCost, d);
            }
            char uChar = labels.charAt(u);
            for (int[] edge : adj[u]) {
                int v = edge[0];
                int weight = edge[1];
                char vChar = labels.charAt(v);
                int vCount;
                if (vChar == uChar) {
                    vCount = uCount + 1;
                } else {
                    vCount = 1;
                }
                if (vCount <= k) {
                    if (d + weight < dist[v][vCount]) {
                        dist[v][vCount] = d + weight;
                        pq.offer(new long[]{d + weight, v, vCount});
                    }
                }
            }
        }
        return (minFinalCost == Long.MAX_VALUE) ? -1 : (int) minFinalCost;
    }
}