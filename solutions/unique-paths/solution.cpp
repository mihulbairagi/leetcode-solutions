class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) {
            std::swap(m, n);
        }
        std::vector<long long> dp(m, 1);
        for (int j = 1; j < n; ++j) {
            for (int i = 1; i < m; ++i) {
                dp[i] += dp[i - 1];
            }
        }
        return dp[m - 1];
    }
};