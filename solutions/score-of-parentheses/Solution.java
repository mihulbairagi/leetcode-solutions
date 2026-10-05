import java.util.ArrayDeque;
import java.util.Deque;
class Solution {
    public int scoreOfParentheses(String s) {
        Deque<Integer> stack = new ArrayDeque<>();
        int currentScore = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                stack.push(currentScore);
                currentScore = 0;
            } else {
                int poppedScore = stack.pop();
                currentScore = poppedScore + Math.max(1, currentScore * 2);
            }
        }
        return currentScore;
    }
}