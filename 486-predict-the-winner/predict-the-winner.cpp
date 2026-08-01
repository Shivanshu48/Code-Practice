class Solution {
public:
    int dfs(int l, int r, vector<int>& nums, vector<vector<int>>& dp) {
        if (l == r) return nums[l];
        if (dp[l][r] != INT_MIN) return dp[l][r];
        return dp[l][r] = max(
            nums[l] - dfs(l + 1, r, nums, dp),
            nums[r] - dfs(l, r - 1, nums, dp)
        );
    }
    
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return dfs(0, n - 1, nums, dp) >= 0;
    }
};