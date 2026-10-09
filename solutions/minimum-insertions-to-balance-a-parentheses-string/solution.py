class Solution:
    def minInsertions(self, s: str) -> int:
        left_open = 0
        insertions = 0
        i = 0
        n = len(s)

        while i < n:
            char = s[i]
            if char == '(':
                left_open += 1
            else:
                # We need to form a "))" pair.
                # Check if the next character is also ')'
                has_second_right_paren = False
                if i + 1 < n and s[i + 1] == ')':
                    has_second_right_paren = True
                    i += 1  # Consume the second ')'

                if left_open > 0:
                    left_open -= 1  # This "))" (or conceptual "))") matches an existing '('
                else:
                    insertions += 1  # No '(' available, insert one '('

                # If we didn't find a second ')' for the current ')' (i.e., it was a single ')'),
                # we need to insert one ')' to complete the "))" pair.
                if not has_second_right_paren:
                    insertions += 1
            i += 1

        # After iterating through the string, any remaining '(' need two ')' each
        insertions += left_open * 2

        return insertions