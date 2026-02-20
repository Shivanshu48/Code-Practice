class Solution {
public:
    int n;
    int t[1001];
    int solve(vector<int> &nums, int target){
        if(target < 0) return 0;
        if(target == 0) return 1;

        if(t[target] != -1) return t[target];

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += solve(nums, target-nums[i]);
        }

        return t[target]  = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, target);
    }
};