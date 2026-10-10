import java.util.Arrays;
import java.util.PriorityQueue;
class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        int[] diff = new int[n];
        for (int i = 0; i < n; i++) {
            diff[i] = Math.abs(nums1[i] - nums2[i]);
        }
        long k = k1 + k2;
        int[] counts = new int[100001];
        int maxDiff = 0;
        for (int d : diff) {
            counts[d]++;
            maxDiff = Math.max(maxDiff, d);
        }
        for (int d = maxDiff; d > 0 && k > 0; d--) {
            int numWithDiff = counts[d];
            if (numWithDiff == 0) {
                continue;
            }
            long reduceAmount = Math.min(numWithDiff, k);
            k -= reduceAmount;
            counts[d] -= reduceAmount;
            counts[d - 1] += reduceAmount;
            if (d - 1 == 0 && counts[d] > 0) {
                k = 0;
            }
        }
        long minSum = 0;
        for (int d = 0; d <= maxDiff; d++) {
            minSum += (long)d * d * counts[d];
        }
        return minSum;
    }
}