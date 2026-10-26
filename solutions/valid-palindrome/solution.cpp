class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            char leftChar = s[left];
            char rightChar = s[right];
            if (!isalnum(leftChar)) {
                left++;
            } else if (!isalnum(rightChar)) {
                right--;
            } else {
                if (tolower(leftChar) != tolower(rightChar)) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};