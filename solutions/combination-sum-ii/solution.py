class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        result = []
        candidates.sort()

        def backtrack(remain, start, current):
            if remain < 0:
                return
            if remain == 0:
                result.append(list(current))
                return

            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                current.append(candidates[i])
                backtrack(remain - candidates[i], i + 1, current)
                current.pop()
        
        backtrack(target, 0, [])
        return result