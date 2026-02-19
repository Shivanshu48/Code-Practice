class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = grid[0][0];
        
        for(int row = 1; row < m; row++){
            dp[row][0] = grid[row][0] + dp[row-1][0];
        }
        for(int col = 1; col < n; col++){
            dp[0][col] = grid[0][col] + dp[0][col-1];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};