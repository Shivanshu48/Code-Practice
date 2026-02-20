class Solution {
public:
    int n;
    int dp[10001];
    vector<int> arr;
    int solve(int i){
        if(i >= 10001){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int take = arr[i] + solve(i+2);
        int skip = solve(i+1);
        return dp[i] = max(take, skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        n = nums.size();
        arr.assign(10001, 0);
        memset(dp, -1, sizeof(dp));
        for(int x : nums){
            arr[x] += x;
        }
        return solve(0);
    }
};