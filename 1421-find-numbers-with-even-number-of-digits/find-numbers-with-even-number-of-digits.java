class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for (int num : nums)
        {
            int digitCount = 0;
            int temp = num;
            while (temp > 0) 
            {
                digitCount++;
                temp /= 10;
            }
            if (digitCount % 2 == 0)
            {
                count++;
            }
        }
        return count;
    }
}