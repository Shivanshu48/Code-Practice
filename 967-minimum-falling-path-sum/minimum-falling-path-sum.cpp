class Solution {
public:
    int n, r, c;
    vector<vector<int>> t;
    int solve(vector<vector<int>> & matrix, int si, int sj){
        if(sj < 0 || sj >= c) return INT_MAX;
        if(si == r-1) return matrix[si][sj];

        if(t[si][sj] != INT_MAX) return t[si][sj];

        int down = solve(matrix, si+1, sj);
        int dleft = solve(matrix, si+1, sj-1);
        int dright = solve(matrix, si+1, sj+1);

        int minsum = min({down, dleft, dright});

        if(minsum == INT_MAX) return t[si][sj] = INT_MAX;

        return t[si][sj] = matrix[si][sj] + minsum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        //memset(t, INT_MAX, sizeof(t));
        t.assign(r, vector<int>(c, INT_MAX));
        int ans = INT_MAX;

        for(int j = 0; j < c; j++){
            ans = min(ans , solve(matrix , 0 , j));
        }
        return ans;
    }
};