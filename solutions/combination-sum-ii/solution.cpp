#include <vector>
#include <algorithm>
#include <functional>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::sort(candidates.begin(), candidates.end());
        std::function<void(int, int, std::vector<int>)> backtrack = 
            [&](int remain, int start, std::vector<int> current) {
            if (remain < 0) {
                return;
            }
            if (remain == 0) {
                result.push_back(current);
                return;
            }

            for (int i = start; i < candidates.size(); ++i) {
                if (i > start && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                current.push_back(candidates[i]);
                backtrack(remain - candidates[i], i + 1, current);
                current.pop_back();
            }
        };
        
        backtrack(target, 0, {});
        return result;
    }
};