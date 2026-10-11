class Solution {
    public int reversePairs(int[] nums) {
        if (nums == null || nums.length < 2) {
            return 0;
        }
        int[] temp = new int[nums.length];
        return mergeSortAndCount(nums, 0, nums.length - 1, temp);
    }
    private int mergeSortAndCount(int[] nums, int low, int high, int[] temp) {
        if (low >= high) {
            return 0;
        }
        int mid = low + (high - low) / 2;
        int count = mergeSortAndCount(nums, low, mid, temp) + mergeSortAndCount(nums, mid + 1, high, temp);
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long)nums[i] > 2 * (long)nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        int i = low;
        j = mid + 1;
        int k = low;
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= high) {
            temp[k++] = nums[j++];
        }
        System.arraycopy(temp, low, nums, low, high - low + 1);
        return count;
    }
}