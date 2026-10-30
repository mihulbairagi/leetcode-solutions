import java.util.*;
class Solution {
    public int shortestPath(int n, int[][] edges, String labels, int k) {
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(new int[]{edge[1], edge[2]});
        }
        int[][][] dist = new int[n][k + 1][26];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                Arrays.fill(dist[i][j], Integer.MAX_VALUE);
            }
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int startCharIndex = labels.charAt(0) - 'a';
        dist[0][0][startCharIndex] = 0;
        pq.offer(new int[]{0, 0, 0, startCharIndex});
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int cost = current[0];
            int u = current[1];
            int consecutive = current[2];
            int lastCharIndex = current[3];
            if (cost > dist[u][consecutive][lastCharIndex]) {
                continue;
            }
            if (u == n - 1) {
                return cost;
            }
            for (int[] neighborInfo : adj.get(u)) {
                int v = neighborInfo[0];
                int weight = neighborInfo[1];
                int currentCharIndex = labels.charAt(v) - 'a';
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
                        pq.offer(new int[]{newCost, v, newConsecutive, currentCharIndex});
                    }
                }
            }
        }
        return -1;
    }
}