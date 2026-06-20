class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        for(int i = 1; i < m; i++){
            int d = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + d);
        }

        for(int i = m - 2; i >= 0; i--){
            int d = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] + d);
        }

        int ans = 0;

        for(int i = 1; i < m; i++){
            long long pos1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long pos2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long d = pos2 - pos1;

            long long peak = (h1 + h2 + d) / 2;

            ans = max(ans, (int)peak);
        }
        return ans;
    }
};