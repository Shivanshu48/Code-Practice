class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        int maxs = 0;
        for(int row = 0; row < m; row++){
            dp[row][0] = matrix[row][0] - '0';
            if(matrix[row][0] == '1'){
                maxs = 1;
            }
        }

        for(int col = 0; col < n; col++){
            dp[0][col] = matrix[0][col] - '0';
            if(matrix[0][col] == '1'){
                maxs = 1;
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]);
                }
                maxs = max(maxs, dp[i][j]);                
            }
        }
        return maxs * maxs;
    }
};