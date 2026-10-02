class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == -2147483648 and divisor == -1:
            return 2147483647
        
        is_negative = (dividend < 0) ^ (divisor < 0)
        a, b = abs(dividend), abs(divisor)
        res = 0
        
        while a >= b:
            temp = b
            multiple = 1
            while a >= (temp << 1):
                temp <<= 1
                multiple <<= 1
            a -= temp
            res += multiple
            
        res = -res if is_negative else res
        return min(max(-2147483648, res), 2147483647)