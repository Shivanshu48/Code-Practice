class Solution {
public:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>>& dp){
        if(i > j) return 0;
        long long mini = LLONG_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        for(int idx = i; idx <= j; idx++){
            long long cost = (long long)cuts[j+1] - cuts[i-1] + solve(i, idx-1, cuts, dp) + solve(idx+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = (int)mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, -1));
        return solve(1, c-2, cuts, dp);
    }
};