public class Solution {
    public int minInsertions(String s) {
        int leftOpen = 0;
        int insertions = 0;
        int i = 0;
        while (i < s.length()) {
            char c = s.charAt(i);
            if (c == '(') {
                leftOpen++;
            } else {
                boolean hasSecondRightParen = false;
                if (i + 1 < s.length() && s.charAt(i + 1) == ')') {
                    hasSecondRightParen = true;
                    i++;
                }
                if (leftOpen > 0) {
                    leftOpen--;
                } else {
                    insertions++;
                }
                if (!hasSecondRightParen) {
                    insertions++;
                }
            }
            i++;
        }
        insertions += leftOpen * 2;
        return insertions;
    }
}