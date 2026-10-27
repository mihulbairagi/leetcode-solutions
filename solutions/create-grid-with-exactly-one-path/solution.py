class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        grid = [['#' for _ in range(n)] for _ in range(m)]

        curr_r, curr_c = 0, 0
        grid[curr_r][curr_c] = '.'

        while curr_r != m - 1 or curr_c != n - 1:
            if curr_r == m - 1:
                curr_c += 1
            elif curr_c == n - 1:
                curr_r += 1
            elif curr_r == curr_c:
                curr_c += 1
            else: 
                curr_r += 1
            grid[curr_r][curr_c] = '.'
        
        return ["".join(row) for row in grid]