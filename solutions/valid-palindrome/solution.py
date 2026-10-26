class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        while left < right:
            left_char = s[left]
            right_char = s[right]
            if not left_char.isalnum():
                left += 1
            elif not right_char.isalnum():
                right -= 1
            else:
                if left_char.lower() != right_char.lower():
                    return False
                left += 1
                right -= 1
        return True