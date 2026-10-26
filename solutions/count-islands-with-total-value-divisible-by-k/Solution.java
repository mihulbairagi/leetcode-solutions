import java.util.ArrayDeque;
import java.util.Queue;
class Solution {
    private int m;
    private int n;
    private int[][] grid;
    private boolean[][] visited;
    private int k;
    private int[] dr = {-1, 1, 0, 0};
    private int[] dc = {0, 0, -1, 1};
    public int countIslands(int[][] grid, int k) {
        this.m = grid.length;
        this.n = grid[0].length;
        this.grid = grid;
        this.k = k;
        this.visited = new boolean[m][n];
        int count = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] > 0 && !visited[r][c]) {
                    if (isIslandDivisible(r, c)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    private boolean isIslandDivisible(int r, int c) {
        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[]{r, c});
        visited[r][c] = true;
        long currentSum = 0;
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int row = curr[0];
            int col = curr[1];
            currentSum += grid[row][col];
            for (int i = 0; i < 4; ++i) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    queue.offer(new int[]{nr, nc});
                }
            }
        }
        return currentSum % k == 0;
    }
}