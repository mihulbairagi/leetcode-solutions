class Solution:
    def sumOfSquares(self, nums: list[int]) -> int:
        n = len(nums)
        sum_sq = 0
        for i in range(1, n + 1):
            if n % i == 0:
                sum_sq += nums[i - 1] * nums[i - 1]
        return sum_sq