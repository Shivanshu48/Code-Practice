class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double currsum = 0;
        for(int i = 0; i < k; i++)
        {
            currsum += nums[i];
        }

        double maxsum = currsum;
        for(int i = k; i < n; i++)
        {
            currsum += nums[i] - nums[i-k];
            maxsum = max(maxsum, currsum);
        }
        return maxsum/k;
    }
};