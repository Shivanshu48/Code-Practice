class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0;      // current consecutive 1's
        int maxCount = 0;   // maximum so far

        for (int num : nums) {
            if (num == 1) {
                count++;
                maxCount = Math.max(maxCount, count);
            } else {
                count = 0;
            }
        }
        return maxCount;
    }
}