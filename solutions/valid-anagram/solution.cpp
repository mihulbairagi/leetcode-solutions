class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int counts[26] = {0};
        for (size_t i = 0; i < s.length(); ++i) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (counts[i] != 0) {
                return false;
            }
        }
        return true;
    }
};