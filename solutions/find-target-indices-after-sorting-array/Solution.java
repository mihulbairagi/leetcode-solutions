import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        List<Integer> result = new ArrayList<>();
        int countLess = 0;
        int countTarget = 0;
        for (int num : nums) {
            if (num < target) {
                countLess++;
            } else if (num == target) {
                countTarget++;
            }
        }
        for (int i = 0; i < countTarget; i++) {
            result.add(countLess + i);
        }
        return result;
    }
}