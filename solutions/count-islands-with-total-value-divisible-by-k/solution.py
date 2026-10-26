from collections import deque

class Solution:
    def countIslands(self, grid: list[list[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        visited = [[False for _ in range(n)] for _ in range(m)]
        count = 0
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]

        def is_island_divisible(r, c):
            q = deque([(r, c)])
            visited[r][c] = True
            current_sum = 0

            while q:
                row, col = q.popleft()
                current_sum += grid[row][col]

                for i in range(4):
                    nr, nc = row + dr[i], col + dc[i]

                    if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] > 0 and not visited[nr][nc]:
                        visited[nr][nc] = True
                        q.append((nr, nc))
            return current_sum % k == 0

        for r in range(m):
            for c in range(n):
                if grid[r][c] > 0 and not visited[r][c]:
                    if is_island_divisible(r, c):
                        count += 1
        return count