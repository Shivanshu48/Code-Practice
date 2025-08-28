class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int j = -1;
        
        // place the pointer j at the first zero
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        // if no zero found, nothing to do
        if (j == -1) return;

        // move non-zeros to front
        for (int i = j + 1; i < n; i++) {
            if (nums[i] != 0) {
                // swap nums[i] and nums[j]
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                j++;
            }
        }
    }
}