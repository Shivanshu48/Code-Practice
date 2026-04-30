class Solution {
public:
    int m;
    int n;
    vector<vector<vector<int>>> t;
    int solve(vector<vector<int>>& grid, int k, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return -1;
        }

        int val = (grid[i][j] == 0) ? 0 : 1;
        if(k < val){
            return -1;
        }

        if(i == m-1 && j == n-1){
            return grid[i][j];
        }

        if(t[i][j][k] != -2){
            return t[i][j][k];
        }

        int right = solve(grid, k-val, i, j+1);
        int down  = solve(grid, k-val, i+1, j);

        int take = max(right, down);

        if(take == -1){
            return t[i][j][k] = -1;
        }

        return t[i][j][k] = grid[i][j] + take;
    }
    
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        t = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k+1, -2)));
        return solve(grid, k, 0, 0);
    }
};