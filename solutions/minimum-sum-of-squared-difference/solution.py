import math

class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        n = len(nums1)
        diff = [abs(nums1[i] - nums2[i]) for i in range(n)]

        k = k1 + k2

        counts = [0] * 100001
        max_diff = 0
        for d in diff:
            counts[d] += 1
            max_diff = max(max_diff, d)

        for d in range(max_diff, 0, -1):
            if counts[d] == 0:
                continue
            
            reduce_amount = min(counts[d], k)
            k -= reduce_amount
            counts[d] -= reduce_amount
            counts[d - 1] += reduce_amount
            
            if d - 1 == 0 and counts[d] > 0:
                k = 0
            
            if k == 0:
                break

        min_sum = 0
        for d in range(max_diff + 1):
            min_sum += d * d * counts[d]

        return min_sum