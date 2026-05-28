class Solution {
public:
    int m, n;
    int t[201][201];

    int solve(int i, int j, vector<vector<int>>& dungeon) {
        if (i >= m || j >= n)
            return 1e9;

        if (t[i][j] != -1)
            return t[i][j];

        if (i == m - 1 && j == n - 1)
            return t[i][j] = (dungeon[i][j] > 0 ? 1 : abs(dungeon[i][j]) + 1);

        int down  = solve(i + 1, j, dungeon);
        int right = solve(i, j + 1, dungeon);

        int res = min(down, right) - dungeon[i][j];
        return t[i][j] = (res > 0 ? res : 1);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, dungeon);
    }
};