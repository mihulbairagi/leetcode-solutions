class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        backtrack(res, curr, 0, 0, n);
        return res;
    }

private:
    void backtrack(vector<string>& res, string& curr, int open, int close, int max) {
        if (curr.length() == max * 2) {
            res.push_back(curr);
            return;
        }
        if (open < max) {
            curr.push_back('(');
            backtrack(res, curr, open + 1, close, max);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            backtrack(res, curr, open, close + 1, max);
            curr.pop_back();
        }
    }
};