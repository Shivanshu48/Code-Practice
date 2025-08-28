class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        if (n == 1) return true;

        // Step-1: Skip the 1st non-decreasing curve
        int pos = 1;
        while (pos < n && nums[pos] >= nums[pos-1]) {
            pos++;
        }

        if (pos == n) return true; // If entire array is still non-decreasing
        if (nums[pos] > nums[0]) return false; // Checking if start of new curve is NOT smallest
        if (pos == n - 1) return true;

        // Step-2: Check the 2nd non-decreasing curve with adjacent & nums[0] value
        pos += 1;
        while (pos < n && nums[pos] <= nums[0] && nums[pos] >= nums[pos-1]) {
            pos++;
        }

        return pos == n;
    }
}