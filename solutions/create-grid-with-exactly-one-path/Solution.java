class Solution {
    public String[] createGrid(int m, int n) {
        char[][] grid = new char[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = '#';
            }
        }
        int currR = 0;
        int currC = 0;
        grid[currR][currC] = '.';
        while (currR != m - 1 || currC != n - 1) {
            if (currR == m - 1) {
                currC++;
            } else if (currC == n - 1) {
                currR++;
            } else if (currR == currC) {
                currC++;
            } else {
                currR++;
            }
            grid[currR][currC] = '.';
        }
        String[] result = new String[m];
        for (int i = 0; i < m; i++) {
            result[i] = new String(grid[i]);
        }
        return result;
    }
}