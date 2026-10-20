import math

class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        sorted_nums = sorted(nums)
        
        total_sum = 0
        for k in range(1, int(math.sqrt(n)) + 1):
            if n % k == 0:
                if self.is_sortable(nums, sorted_nums, k):
                    total_sum += k
                if k * k != n:
                    k2 = n // k
                    if self.is_sortable(nums, sorted_nums, k2):
                        total_sum += k2
        return totalSum

    def is_sortable(self, original: list[int], sorted_arr: list[int], k: int) -> bool:
        n = len(original)
        for i in range(0, n, k):
            block_start = i
            first_mismatch = -1
            for j in range(k):
                if original[block_start + j] != sorted_arr[i + j]:
                    first_mismatch = j
                    break
            
            if first_mismatch == -1:
                continue

            current_idx = block_start + first_mismatch
            target_idx = i + first_mismatch
            original_value = original[current_idx]
            rotations = 0

            while original[current_idx] != sorted_arr[target_idx]:
                next_idx = (current_idx - block_start + 1) % k + block_start
                if original[next_idx] == original_value and next_idx != current_idx:
                    return False
                current_idx = next_idx
                rotations += 1
                if rotations > k:
                    return False
            
            mismatch_count = 0
            for j in range(k):
                if original[i + j] != sorted_arr[i + j]:
                    mismatch_count += 1
            if mismatch_count > 0:
                return False
        return True