class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        maxLength = 0
        left = 0
        charSet = set()

        for right in range(n):
            currentChar = s[right]
            while currentChar in charSet:
                charSet.remove(s[left])
                left += 1
            charSet.add(currentChar)
            maxLength = max(maxLength, right - left + 1)

        return maxLength