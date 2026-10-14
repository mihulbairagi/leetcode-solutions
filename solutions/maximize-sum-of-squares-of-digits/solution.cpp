class Solution {
public:
    std::string maxSumOfSquares(int num, int sum) {
        if (sum < 1 || sum > 9 * num) {
            return "";
        }
        
        std::string result = "";
        int remainingSum = sum;
        for (int i = 0; i < num; ++i) {
            int digit = 0;
            for (int d = 9; d >= 0; --d) {
                if (remainingSum >= d && (remainingSum - d) <= (num - 1 - i) * 9) {
                    digit = d;
                    break;
                }
            }
            result += std::to_string(digit);
            remainingSum -= digit;
        }
        
        if (remainingSum != 0) {
            return "";
        }
        
        return result;
    }
};