class Solution {
    public void sortColors(int[] nums) {
        int zero = 0;
        int two = nums.length - 1;
        int curr = 0;
        while (curr <= two) {
            if (nums[curr] == 0) {
                int temp = nums[curr];
                nums[curr] = nums[zero];
                nums[zero] = temp;
                zero++;
                curr++;
            } else if (nums[curr] == 2) {
                int temp = nums[curr];
                nums[curr] = nums[two];
                nums[two] = temp;
                two--;
            } else {
                curr++;
            }
        }
    }
}