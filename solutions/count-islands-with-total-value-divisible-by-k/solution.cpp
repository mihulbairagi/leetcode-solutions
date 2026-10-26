#include <vector>
#include <queue>

class Solution {
public:
    int m;
    int n;
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<bool>> visited;
    int k;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        this.m = grid.size();
        this.n = grid[0].size();
        this.grid = grid;
        this.k = k;
        this.visited.assign(m, std::vector<bool>(n, false));
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

private:
    bool isIslandDivisible(int r, int c) {
        std::queue<std::pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        long long currentSum = 0;

        while (!q.empty()) {
            std::pair<int, int> curr = q.front();
            q.pop();
            int row = curr.first;
            int col = curr.second;
            currentSum += grid[row][col];

            for (int i = 0; i < 4; ++i) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return currentSum % k == 0;
    }
};