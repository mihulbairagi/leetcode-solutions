#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());
        
        int totalSum = 0;
        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                if (isSortable(nums, sortedNums, k)) {
                    totalSum += k;
                }
                if (k * k != n) {
                    int k2 = n / k;
                    if (isSortable(nums, sortedNums, k2)) {
                        totalSum += k2;
                    }
                }
            }
        }
        return totalSum;
    }

private:
    bool isSortable(const std::vector<int>& original, const std::vector<int>& sorted, int k) {
        int n = original.size();
        for (int i = 0; i < n; i += k) {
            int blockStart = i;
            int firstMismatch = -1;
            for (int j = 0; j < k; ++j) {
                if (original[blockStart + j] != sorted[i + j]) {
                    firstMismatch = j;
                    break;
                }
            }
            
            if (firstMismatch == -1) {
                continue;
            }

            int currentIdx = blockStart + firstMismatch;
            int targetIdx = i + firstMismatch;
            int originalValue = original[currentIdx];
            int rotations = 0;

            while (original[currentIdx] != sorted[targetIdx]) {
                int nextIdx = (currentIdx - blockStart + 1) % k + blockStart;
                if (original[nextIdx] == originalValue && nextIdx != currentIdx) {
                    return false;
                }
                currentIdx = nextIdx;
                rotations++;
                if (rotations > k) {
                    return false;
                }
            }
            
            int mismatchCount = 0;
            for (int j = 0; j < k; ++j) {
                if (original[i + j] != sorted[i + j]) {
                    mismatchCount++;
                }
            }
            if (mismatchCount > 0) {
                return false;
            }
        }
        return true;
    }
};