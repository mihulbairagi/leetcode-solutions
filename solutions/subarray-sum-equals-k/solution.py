class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        count = 0
        current_sum = 0
        prefix_sum_count = {0: 1}

        for num in nums:
            current_sum += num
            if (current_sum - k) in prefix_sum_count:
                count += prefix_sum_count[current_sum - k]
            prefix_sum_count[current_sum] = prefix_sum_count.get(current_sum, 0) + 1

        return count