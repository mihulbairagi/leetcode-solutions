class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        numSet = set(nums)
        longestStreak = 0

        for num in numSet:
            if num - 1 not in numSet:
                currentNum = num
                currentStreak = 1

                while currentNum + 1 in numSet:
                    currentNum += 1
                    currentStreak += 1
                
                longestStreak = max(longestStreak, currentStreak)
        
        return longestStreak