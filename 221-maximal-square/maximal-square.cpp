class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int max_sq[m][n];
        int max_side_length = 0;

        for(int j=0; j<n; j++) {                
            max_sq[0][j] = matrix[0][j] - '0';
            if(matrix[0][j] == '1')
                max_side_length = 1;
        }
        for(int i=0; i<m; i++) {
            max_sq[i][0] = matrix[i][0] - '0';
            if(matrix[i][0] == '1')
                max_side_length = 1;
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == '0')
                    max_sq[i][j] = 0;
                else
                    max_sq[i][j] = 1 + min(min(max_sq[i-1][j], max_sq[i-1][j-1]), max_sq[i][j-1]);
                max_side_length = max(max_side_length, max_sq[i][j]);                
            }
        }
        return max_side_length * max_side_length;
    }
};