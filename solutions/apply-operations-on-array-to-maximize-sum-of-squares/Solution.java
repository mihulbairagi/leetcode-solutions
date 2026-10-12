class Solution {
    public int maxSum(List<Integer> nums, int k) {
        int[] bitCounts = new int[30];
        for (int num : nums) {
            for (int p = 0; p < 30; p++) {
                if (((num >> p) & 1) == 1) {
                    bitCounts[p]++;
                }
            }
        }
        long[] finalNums = new long[k];
        for (int p = 0; p < 30; p++) {
            for (int i = 0; i < k; i++) {
                if (bitCounts[p] > i) {
                    finalNums[i] |= (1L << p);
                }
            }
        }
        long totalSumSquares = 0;
        long MOD = 1_000_000_007;
        for (long val : finalNums) {
            totalSumSquares = (totalSumSquares + (val % MOD * (val % MOD))) % MOD;
        }
        return (int) totalSumSquares;
    }
}