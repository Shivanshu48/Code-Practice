class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int endLand = landStartTime[i] + landDuration[i];
                int startWater = max(endLand, waterStartTime[j]);
                ans = min(ans, startWater + waterDuration[j]);

                int endWater = waterStartTime[j] + waterDuration[j];
                int startLand = max(endWater, landStartTime[i]);
                ans = min(ans, startLand + landDuration[i]);
            }
        }
        return ans;
    }
};