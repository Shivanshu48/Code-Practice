class Solution {
public:
    
    bool isSafe(vector<string> &grid, int r, int c, int n){
        for(int j = 0; j < n; j++){
            if(grid[r][j] == 'Q'){
                return false;
            }
        }

        for(int i = 0; i < n; i++){
            if(grid[i][c] == 'Q'){
                return false;
            }
        }

        for(int i = r, j = c; i >= 0 && j >= 0; i--,j--){
            if(grid[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = r, j = c; i >= 0 && j < n; i--,j++){
            if(grid[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void nQueens(vector<string> &grid, int r, int n, vector<vector<string>> &res){
        if(r == n){
            res.push_back({grid});
            return;
        }

        for(int j = 0; j < n; j++){
            if(isSafe(grid, r, j, n)){
                grid[r][j] = 'Q';
                nQueens(grid, r+1, n, res);
                grid[r][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> res;
        nQueens(grid, 0, n, res);
        return res;
    }
};