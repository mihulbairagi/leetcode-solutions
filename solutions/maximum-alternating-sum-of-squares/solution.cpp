#include <vector>
#include <algorithm>
#include <cmath> 

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            return std::abs(a) < std::abs(b);
        });

        long long maxScore = 0;
        int n = nums.size();
        int splitPoint = n / 2; 

        for (int i = 0; i < splitPoint; ++i) {
            maxScore -= (long long)nums[i] * nums[i];
        }

        for (int i = splitPoint; i < n; ++i) {
            maxScore += (long long)nums[i] * nums[i];
        }

        return maxScore;
    }
};