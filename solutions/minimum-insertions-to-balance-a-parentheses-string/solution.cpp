class Solution {
public:
    int minInsertions(std::string s) {
        int leftOpen = 0;
        int insertions = 0;
        int i = 0;
        int n = s.length();

        while (i < n) {
            char c = s[i];
            if (c == '(') {
                leftOpen++;
            } else { 
                // We need to form a "))" pair.
                // Check if the next character is also ')'
                bool hasSecondRightParen = false;
                if (i + 1 < n && s[i + 1] == ')') {
                    hasSecondRightParen = true;
                    i++; // Consume the second ')'
                }

                if (leftOpen > 0) {
                    leftOpen--; // This "))" (or conceptual "))") matches an existing '('
                } else {
                    insertions++; // No '(' available, insert one '('
                }

                // If we didn't find a second ')' for the current ')' (i.e., it was a single ')'),
                // we need to insert one ')' to complete the "))" pair.
                if (!hasSecondRightParen) {
                    insertions++;
                }
            }
            i++;
        }

        // After iterating through the string, any remaining '(' need two ')' each
        insertions += leftOpen * 2;

        return insertions;
    }
};