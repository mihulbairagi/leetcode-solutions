import java.util.HashSet;
import java.util.Set;
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int duplicate = -1;
        long actualSum = 0;
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (seen.contains(num)) {
                duplicate = num;
            }
            seen.add(num);
            actualSum += num;
        }
        long expectedSum = (long) n * (n + 1) / 2;
        int missing = (int) (expectedSum - (actualSum - duplicate));
        return new int[]{duplicate, missing};
    }
}