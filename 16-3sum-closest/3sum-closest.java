class Solution {
    public int threeSumClosest(int[] nums, int target) {
         Arrays.sort(nums); // Step 1: Sort the array
        int n = nums.length;
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the first possible sum

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];

                // If exact match, return immediately
                if (currSum == target) {
                    return currSum;
                }

                // Update closest sum if needed
                if (Math.abs(currSum - target) < Math.abs(closestSum - target)) {
                    closestSum = currSum;
                }

                // Move pointers based on comparison
                if (currSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closestSum;
    }
}