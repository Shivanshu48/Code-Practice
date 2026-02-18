class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int mod = 1e9+7;
        vector<vector<long long>> dpmin(n, vector<long long>(m, -1));
        vector<vector<long long>> dpmax(n, vector<long long>(m, -1));
        dpmin[0][0] = dpmax[0][0] = grid[0][0];
        for(int row = 1; row < n; row++){
            dpmin[row][0] = grid[row][0] * dpmin[row-1][0];
            dpmax[row][0] = grid[row][0] * dpmax[row-1][0];
        }

        for(int col = 1; col < m; col++){
            dpmin[0][col] = grid[0][col] * dpmin[0][col-1];
            dpmax[0][col] = grid[0][col] * dpmax[0][col-1];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                long long val = grid[i][j];

                long long a = dpmax[i-1][j] * val;
                long long b = dpmin[i-1][j] * val;
                long long c = dpmax[i][j-1] * val;
                long long d = dpmin[i][j-1] * val;

                dpmax[i][j] = max({a, b, c, d});
                dpmin[i][j] = min({a, b, c, d});
            }
        }

        long long ans = dpmax[n-1][m-1];
        return ans < 0 ? -1 : ans % mod;
    }
};