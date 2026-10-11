class Solution:
    def reversePairs(self, nums: list[int]) -> int:
        if not nums or len(nums) < 2:
            return 0
        
        temp = [0] * len(nums)
        return self._merge_sort_and_count(nums, 0, len(nums) - 1, temp)

    def _merge_sort_and_count(self, nums: list[int], low: int, high: int, temp: list[int]) -> int:
        if low >= high:
            return 0
        
        mid = low + (high - low) // 2
        count = self._merge_sort_and_count(nums, low, mid, temp) + \
                self._merge_sort_and_count(nums, mid + 1, high, temp)

        j = mid + 1
        for i in range(low, mid + 1):
            while j <= high and nums[i] > 2 * nums[j]:
                j += 1
            count += (j - (mid + 1))
        
        i = low
        j = mid + 1
        k = low

        while i <= mid and j <= high:
            if nums[i] <= nums[j]:
                temp[k] = nums[i]
                i += 1
            else:
                temp[k] = nums[j]
                j += 1
            k += 1
        
        while i <= mid:
            temp[k] = nums[i]
            i += 1
            k += 1
        
        while j <= high:
            temp[k] = nums[j]
            j += 1
            k += 1
            
        for idx in range(low, high + 1):
            nums[idx] = temp[idx]
        
        return count