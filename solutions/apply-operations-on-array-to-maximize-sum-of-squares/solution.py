class Solution:
    def maxSum(self, nums: list[int], k: int) -> int:
        bit_counts = [0] * 30
        for num in nums:
            for p in range(30):
                if (num >> p) & 1:
                    bit_counts[p] += 1
        
        final_nums = [0] * k
        for p in range(30):
            for i in range(k):
                if bit_counts[p] > i:
                    final_nums[i] |= (1 << p)
        
        total_sum_squares = 0
        MOD = 10**9 + 7
        
        for val in final_nums:
            total_sum_squares = (total_sum_squares + (val % MOD * (val % MOD))) % MOD
            
        return total_sum_squares