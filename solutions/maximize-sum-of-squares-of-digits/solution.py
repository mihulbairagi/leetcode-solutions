class Solution:
    def maxSumOfSquares(self, num: int, sum_val: int) -> str:
        if sum_val < 1 or sum_val > 9 * num:
            return ""
        
        result = []
        remaining_sum = sum_val
        for i in range(num):
            digit = 0
            for d in range(9, -1, -1):
                if remaining_sum >= d and (remaining_sum - d) <= (num - 1 - i) * 9:
                    digit = d
                    break
            result.append(str(digit))
            remaining_sum -= digit
            
        if remaining_sum != 0:
            return ""
            
        return "".join(result)