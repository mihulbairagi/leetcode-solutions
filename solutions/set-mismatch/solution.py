class Solution:
    def findErrorNums(self, nums: list[int]) -> list[int]:
        n = len(nums)
        duplicate = -1
        actual_sum = 0
        seen = set()

        for num in nums:
            if num in seen:
                duplicate = num
            seen.add(num)
            actual_sum += num

        expected_sum = n * (n + 1) // 2
        missing = expected_sum - (actual_sum - duplicate)

        return [duplicate, missing]