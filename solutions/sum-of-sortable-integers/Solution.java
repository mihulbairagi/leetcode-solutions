import java.util.Arrays;
class Solution {
    public int sortableIntegers(int[] nums) {
        int n = nums.length;
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);
        int totalSum = 0;
        for (int k = 1; k * k <= n; ++k) {
            if (n % k == 0) {
                if (isSortable(nums, sortedNums, k)) {
                    totalSum += k;
                }
                if (k * k != n) {
                    int k2 = n / k;
                    if (isSortable(nums, sortedNums, k2)) {
                        totalSum += k2;
                    }
                }
            }
        }
        return totalSum;
    }
    private boolean isSortable(int[] original, int[] sorted, int k) {
        int n = original.length;
        for (int i = 0; i < n; i += k) {
            boolean[] visited = new boolean[k];
            int currentBlockStart = i;
            int targetBlockStart = -1;
            for (int j = 0; j < k; ++j) {
                if (original[currentBlockStart + j] != sorted[i + j]) {
                    targetBlockStart = j;
                    break;
                }
            }
            if (targetBlockStart == -1) {
                continue;
            }
            int currentIdx = currentBlockStart + targetBlockStart;
            int targetIdx = i + targetBlockStart;
            int originalValue = original[currentIdx];
            int rotations = 0;
            while (original[currentIdx] != sorted[targetIdx]) {
                int nextIdx = (currentIdx - currentBlockStart + 1) % k + currentBlockStart;
                if (original[nextIdx] == originalValue && nextIdx != currentIdx) {
                    return false;
                }
                currentIdx = nextIdx;
                rotations++;
                if (rotations > k) {
                    return false;
                }
            }
            int count = 0;
            for (int j = 0; j < k; ++j) {
                if (original[i + j] != sorted[i + j]) {
                    count++;
                }
            }
            if (count > 0) {
                return false;
            }
        }
        return true;
    }
}