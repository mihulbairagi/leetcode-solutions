#include <vector>
#include <algorithm>

class Solution {
public:
    int reversePairs(std::vector<int>& nums) {
        if (nums.empty() || nums.size() < 2) {
            return 0;
        }
        std::vector<int> temp(nums.size());
        return mergeSortAndCount(nums, 0, nums.size() - 1, temp);
    }

private:
    int mergeSortAndCount(std::vector<int>& nums, int low, int high, std::vector<int>& temp) {
        if (low >= high) {
            return 0;
        }

        int mid = low + (high - low) / 2;
        int count = mergeSortAndCount(nums, low, mid, temp) + mergeSortAndCount(nums, mid + 1, high, temp);

        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2 * (long long)nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        int i = low;
        j = mid + 1;
        int k = low;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= high) {
            temp[k++] = nums[j++];
        }

        for (int idx = low; idx <= high; idx++) {
            nums[idx] = temp[idx];
        }
        
        return count;
    }
};