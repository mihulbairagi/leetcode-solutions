#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        std::vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = std::abs(nums1[i] - nums2[i]);
        }

        long long k = (long long)k1 + k2;

        std::vector<int> counts(100001, 0);
        int maxDiff = 0;
        for (int d : diff) {
            counts[d]++;
            maxDiff = std::max(maxDiff, d);
        }

        for (int d = maxDiff; d > 0 && k > 0; --d) {
            int numWithDiff = counts[d];
            if (numWithDiff == 0) {
                continue;
            }

            long long reduceAmount = std::min((long long)numWithDiff, k);
            k -= reduceAmount;

            counts[d] -= reduceAmount;
            counts[d - 1] += reduceAmount;
            
            if (d - 1 == 0 && counts[d] > 0) {
                k = 0;
            }
        }

        long long minSum = 0;
        for (int d = 0; d <= maxDiff; ++d) {
            minSum += (long long)d * d * counts[d];
        }

        return minSum;
    }
};