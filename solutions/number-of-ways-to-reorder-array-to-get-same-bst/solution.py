from math import comb

class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        if n <= 2:
            return 0

        # Precompute combinations using Pascal's triangle for efficiency
        self.combinations = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            self.combinations[i][0] = 1
            for j in range(1, i + 1):
                self.combinations[i][j] = (self.combinations[i-1][j-1] + self.combinations[i-1][j]) % MOD

        def solve(arr):
            if len(arr) <= 2:
                return 1
            
            root = arr[0]
            left = [x for x in arr[1:] if x < root]
            right = [x for x in arr[1:] if x >= root]
            
            left_ways = solve(left)
            right_ways = solve(right)
            
            ways_to_combine = self.combinations[len(arr) - 1][len(left)]
            
            total = (ways_to_combine * left_ways) % MOD
            total = (total * right_ways) % MOD
            return total

        return (solve(nums) - 1 + MOD) % MOD