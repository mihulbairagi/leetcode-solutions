#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int scoreOfParentheses(std::string s) {
        std::stack<int> st;
        int currentScore = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(currentScore);
                currentScore = 0;
            } else {
                int poppedScore = st.top();
                st.pop();
                currentScore = poppedScore + std::max(1, currentScore * 2);
            }
        }

        return currentScore;
    }
};