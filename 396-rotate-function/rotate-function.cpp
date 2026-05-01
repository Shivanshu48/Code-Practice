class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans += i*nums[i];
        }
        int result = ans;
        for(int k = 0; k <= n-1; k++){
            int newans = ans + sum - n*nums[n-1-k];
            result = max(result, newans);
            ans = newans;
        }
        return result;
    }
};