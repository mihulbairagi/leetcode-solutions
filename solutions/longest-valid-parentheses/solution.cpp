#include <string>
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int maxLen = 0;
        std::stack<int> st;
        st.push(-1);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxLen = std::max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};