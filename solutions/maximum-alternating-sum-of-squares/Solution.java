import java.util.Arrays;
import java.util.Comparator;
import java.lang.Math;
class Solution {
    public long maxAlternatingSum(int[] nums) {
        Integer[] boxedNums = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            boxedNums[i] = nums[i];
        }
        Arrays.sort(boxedNums, Comparator.comparingInt(Math::abs));
        long maxScore = 0;
        int n = boxedNums.length;
        int splitPoint = n / 2;
        for (int i = 0; i < splitPoint; i++) {
            maxScore -= (long) boxedNums[i] * boxedNums[i];
        }
        for (int i = splitPoint; i < n; i++) {
            maxScore += (long) boxedNums[i] * boxedNums[i];
        }
        return maxScore;
    }
}