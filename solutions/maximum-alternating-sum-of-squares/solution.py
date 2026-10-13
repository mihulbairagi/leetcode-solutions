import math

class Solution:
    def maxAlternatingSum(self, nums: list[int]) -> int:
        nums.sort(key=abs)
        
        max_score = 0
        n = len(nums)
        
        split_point = n // 2 
        
        for i in range(split_point):
            max_score -= nums[i] * nums[i]
            
        for i in range(split_point, n):
            max_score += nums[i] * nums[i]
            
        return max_score