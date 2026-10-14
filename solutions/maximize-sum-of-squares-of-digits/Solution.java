class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (sum < 1 || sum > 9 * num) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        int remainingSum = sum;
        for (int i = 0; i < num; ++i) {
            int digit = 0;
            for (int d = 9; d >= 0; --d) {
                if (remainingSum >= d && (remainingSum - d) <= (num - 1 - i) * 9) {
                    digit = d;
                    break;
                }
            }
            sb.append(digit);
            remainingSum -= digit;
        }
        if (remainingSum != 0) {
            return "";
        }
        return sb.toString();
    }
}