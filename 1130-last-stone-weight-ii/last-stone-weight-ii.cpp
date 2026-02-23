class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int x : stones){
            sum += x;
        }
        int target = sum / 2;

        vector<bool> dp(target+1, false);
        dp[0] = true;

        for(int w : stones){
            for(int j = target; j >= w; j--){
                dp[j] = dp[j] || dp[j-w];
            }
        }

        for(int s = target; s >= 0; s--){
            if(dp[s]){
                return sum - 2*s;
            }
        }
        return 0;
    }
};