import java.util.Arrays;
import java.util.Comparator;
class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        Integer[] indexedNums = new Integer[n];
        for (int i = 0; i < n; i++) {
            indexedNums[i] = nums[i];
        }
        Arrays.sort(indexedNums, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                int sumA = getDigitSum(a);
                int sumB = getDigitSum(b);
                if (sumA != sumB) {
                    return Integer.compare(sumA, sumB);
                } else {
                    return Integer.compare(a, b);
                }
            }
        });
        int[] sortedNums = new int[n];
        for (int i = 0; i < n; i++) {
            sortedNums[i] = indexedNums[i];
        }
        java.util.Map<Integer, Integer> pos = new java.util.HashMap<>();
        for (int i = 0; i < n; i++) {
            pos.put(nums[i], i);
        }
        boolean[] visited = new boolean[n];
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || nums[i] == sortedNums[i]) {
                continue;
            }
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                int currentVal = nums[j];
                int targetIndex = -1;
                for(int k=0; k<n; k++) {
                    if (sortedNums[k] == currentVal) {
                        targetIndex = k;
                        break;
                    }
                }
                int nextValInOriginalArray = -1;
                for(int k=0; k<n; k++) {
                    if (nums[k] == sortedNums[targetIndex]) {
                        nextValInOriginalArray = k;
                        break;
                    }
                }
                j = nextValInOriginalArray;
                cycle_size++;
            }
            if (cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    }
    private int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}