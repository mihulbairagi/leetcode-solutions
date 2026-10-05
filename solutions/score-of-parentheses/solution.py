class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack = []
        current_score = 0

        for char in s:
            if char == '(': # Dive deeper
                stack.append(current_score)
                current_score = 0
            else: # Come up a level
                popped_score = stack.pop()
                # (A) -> 2 * A, but () -> 1 (not 0*2)
                current_score = popped_score + max(1, current_score * 2)
        
        return current_score