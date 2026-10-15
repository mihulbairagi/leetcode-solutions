class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        n = len(nums)
        total_sum_of_squares = 0

        for i in range(n):
            distinct_elements = set()
            for j in range(i, n):
                distinct_elements.add(nums[j])
                distinct_count = len(distinct_elements)
                total_sum_of_squares += distinct_count * distinct_count

        return total_sum_of_squares