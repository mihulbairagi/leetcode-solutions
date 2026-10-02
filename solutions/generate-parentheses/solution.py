class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        res = []
        
        def backtrack(open_count: int, close_count: int, curr: list[str]) -> None:
            if len(curr) == 2 * n:
                res.append("".join(curr))
                return
            if open_count < n:
                curr.append("(")
                backtrack(open_count + 1, close_count, curr)
                curr.pop()
            if close_count < open_count:
                curr.append(")")
                backtrack(open_count, close_count + 1, curr)
                curr.pop()
                
        backtrack(0, 0, [])
        return res