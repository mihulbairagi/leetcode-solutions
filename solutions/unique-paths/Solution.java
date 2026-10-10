class Solution {
    public int uniquePaths(int m, int n) {
        if (m > n) {
            return uniquePaths(n, m);
        }
        long[] dp = new long[m];
        for (int i = 0; i < m; i++) {
            dp[i] = 1;
        }
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++) {
                dp[i] = dp[i] + dp[i - 1];
            }
        }
        return (int) dp[m - 1];
    }
}