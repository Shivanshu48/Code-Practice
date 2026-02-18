class Solution {
public:
    int m ,n;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        
        vector<vector<int>> t(m, vector<int>(n, 0));
        
        for(int i = m - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                if(i == m-1 && j == n-1){
                    t[i][j] = (dungeon[m-1][n-1] > 0 ? 1 : abs(dungeon[m-1][n-1]) + 1);
                } 
                else{
                    int down  = (i+1 >= m) ? 1e9 : t[i+1][j]; 
                    int right = (j+1 >= n) ? 1e9 : t[i][j+1];
                    int res = min(down, right) - dungeon[i][j]; 
                    t[i][j] = (res > 0 ? res : 1);
                }
            }
        }
        return t[0][0];
    }
};