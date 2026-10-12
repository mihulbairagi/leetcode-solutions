#include <vector>
#include <numeric>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        std::vector<int> bitCounts(30, 0);
        for (int num : nums) {
            for (int p = 0; p < 30; p++) {
                if ((num >> p) & 1) {
                    bitCounts[p]++;
                }
            }
        }

        std::vector<long long> finalNums(k, 0);
        for (int p = 0; p < 30; p++) {
            for (int i = 0; i < k; i++) {
                if (bitCounts[p] > i) {
                    finalNums[i] |= (1LL << p);
                }
            }
        }

        long long totalSumSquares = 0;
        long long MOD = 1e9 + 7;

        for (long long val : finalNums) {
            totalSumSquares = (totalSumSquares + (val % MOD * (val % MOD))) % MOD;
        }

        return static_cast<int>(totalSumSquares);
    }
};