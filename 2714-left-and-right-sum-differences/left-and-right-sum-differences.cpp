class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        vector<int> leftSum(n);
        vector<int> rightSum(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            leftSum[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        for(int i = n-1; i >= 0; i--){
            rightSum[i] = sum;
            sum += nums[i];
        }

        for(int i = 0; i < n; i++){
            ans[i] = abs(leftSum[i]-rightSum[i]);
        }
        return ans;
    }
};