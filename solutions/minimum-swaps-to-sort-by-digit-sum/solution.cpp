#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

class Solution {
public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> sortedNums = nums;

        std::sort(sortedNums.begin(), sortedNums.end(), [&](int a, int b) {
            int sumA = getDigitSum(a);
            int sumB = getDigitSum(b);
            if (sumA != sumB) {
                return sumA < sumB;
            } else {
                return a < b;
            }
        });

        std::map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[nums[i]] = i;
        }

        std::vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || nums[i] == sortedNums[i]) {
                continue;
            }

            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                int currentVal = nums[j];
                auto it = std::find(sortedNums.begin(), sortedNums.end(), currentVal);
                int targetIndex = std::distance(sortedNums.begin(), it);
                
                auto itNums = std::find(nums.begin(), nums.end(), sortedNums[targetIndex]);
                j = std::distance(nums.begin(), itNums);
                
                cycle_size++;
            }

            if (cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    }

private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};