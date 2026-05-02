class Solution {
public:
    typedef long long ll;
    int n;
    ll t[100001][2];
    ll solve(vector<int>& nums, int i, bool flag){
        if(i >= n) return 0;

        if(t[i][flag] != -1) return t[i][flag];

        ll skip = solve(nums, i+1, flag);
        ll value = nums[i];
        if(flag == false){
            value = -value;
        }

        ll take = solve(nums, i+1, !flag) + value;

        return t[i][flag] = max(take, skip);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        bool flag = true;
        return solve(nums, 0, flag);
    }
};