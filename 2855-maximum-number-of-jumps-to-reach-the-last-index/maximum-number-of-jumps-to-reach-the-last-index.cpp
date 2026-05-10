class Solution {
public:
    int n;
    int solve(vector<int>& nums, int target, int idx, vector<int>& dp){
        if(idx == n-1){
            return dp[idx] = 0;
        }

        if(dp[idx] != -2){
            return dp[idx];
        }
        int ans = -1;
        for(int i = idx+1; i < n; i++){
            if(abs(nums[idx] - nums[i]) <= target){
                int res = solve(nums, target, i, dp);
                if(res != -1){
                    ans = max(1+res, ans);
                }
            }
        }
        return dp[idx] = ans;
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> dp(n+1, -2);
        return solve(nums, target, 0, dp);
    }
};