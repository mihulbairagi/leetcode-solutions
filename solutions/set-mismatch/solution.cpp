#include <vector>
#include <numeric>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int n = nums.size();
        int duplicate = -1;
        long long actualSum = 0;
        std::unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                duplicate = num;
            }
            seen.insert(num);
            actualSum += num;
        }

        long long expectedSum = (long long)n * (n + 1) / 2;
        int missing = expectedSum - (actualSum - duplicate);

        return {duplicate, missing};
    }
};