from typing import List

class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        result = []
        count_less = 0
        count_target = 0

        for num in nums:
            if num < target:
                count_less += 1
            elif num == target:
                count_target += 1
        
        for i in range(count_target):
            result.append(count_less + i)
            
        return result