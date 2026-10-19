#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        std::vector<int> result;
        int countLess = 0;
        int countTarget = 0;

        for (int num : nums) {
            if (num < target) {
                countLess++;
            } else if (num == target) {
                countTarget++;
            }
        }

        for (int i = 0; i < countTarget; ++i) {
            result.push_back(countLess + i);
        }

        return result;
    }
};