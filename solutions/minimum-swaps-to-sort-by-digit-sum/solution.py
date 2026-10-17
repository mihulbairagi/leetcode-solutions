class Solution:
    def minSwaps(self, nums):
        n = len(nums)
        
        def get_digit_sum(num):
            s = 0
            while num > 0:
                s += num % 10
                num //= 10
            return s
        
        sorted_nums = sorted(nums, key=lambda x: (get_digit_sum(x), x))
        
        pos = {val: i for i, val in enumerate(nums)}
        
        visited = [False] * n
        swaps = 0
        
        for i in range(n):
            if visited[i] or nums[i] == sorted_nums[i]:
                continue
            
            cycle_size = 0
            j = i
            while not visited[j]:
                visited[j] = True
                current_val = nums[j]
                
                target_idx_in_sorted = -1
                for k in range(n):
                    if sorted_nums[k] == current_val:
                        target_idx_in_sorted = k
                        break
                
                next_val_in_original = -1
                for k in range(n):
                    if nums[k] == sorted_nums[target_idx_in_sorted]:
                        next_val_in_original = k
                        break
                
                j = next_val_in_original
                cycle_size += 1
            
            if cycle_size > 0:
                swaps += (cycle_size - 1)
        
        return swaps