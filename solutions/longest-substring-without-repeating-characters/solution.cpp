#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0;
        std::unordered_set<char> charSet;

        for (int right = 0; right < n; right++) {
            char currentChar = s[right];
            while (charSet.count(currentChar)) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(currentChar);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};