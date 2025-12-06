class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int maxlen = INT_MAX;
        int l = 0;
        int currsum = 0;

        for(int r=0; r<n; r++){
            currsum += nums[r];

            while(currsum >= target){
                maxlen = min(maxlen, r-l+1);
                currsum -= nums[l];
                l++;
            }
        }
        return (maxlen == INT_MAX)?0:maxlen;
    }
};