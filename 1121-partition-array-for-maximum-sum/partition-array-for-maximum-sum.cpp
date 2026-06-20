class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<int>& arr, int k){
        int n = arr.size();

        if(i == n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int mx = 0, ans = 0;

        for(int len = 1; len <= k && i + len <= n; len++){
            mx = max(mx, arr[i + len - 1]);
            ans = max(ans, mx * len + solve(i + len, arr, k));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.assign(n, -1);
        return solve(0, arr, k);
    }
};