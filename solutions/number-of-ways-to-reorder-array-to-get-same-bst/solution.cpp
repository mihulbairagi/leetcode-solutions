#include <vector>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> combinations;

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        combinations.resize(n + 1, vector<long long>(n + 1));
        precomputeCombinations(n);

        return (int) (solve(nums) - 1);
    }

private:
    long long solve(vector<int>& nodes) {
        int n = nodes.size();
        if (n <= 2) {
            return 1;
        }

        int rootVal = nodes[0];
        vector<int> leftSubtree;
        vector<int> rightSubtree;

        for (int i = 1; i < n; ++i) {
            if (nodes[i] < rootVal) {
                leftSubtree.push_back(nodes[i]);
            } else {
                rightSubtree.push_back(nodes[i]);
            }
        }

        long long leftWays = solve(leftSubtree);
        long long rightWays = solve(rightSubtree);
        long long waysToCombine = combinations[n - 1][leftSubtree.size()];

        long long totalWays = (waysToCombine * leftWays) % MOD;
        totalWays = (totalWays * rightWays) % MOD;

        return totalWays;
    }

    void precomputeCombinations(int n) {
        for (int i = 0; i <= n; ++i) {
            combinations[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                combinations[i][j] = (combinations[i - 1][j - 1] + combinations[i - 1][j]) % MOD;
            }
        }
    }
};