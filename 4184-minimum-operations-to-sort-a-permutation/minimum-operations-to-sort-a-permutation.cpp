class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        int pos0 = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool flag = true;
        for(int i = 0; i < n; i++){
            if(nums[i] != (i-pos0+n) % n){
                flag = false;
                break;
            }
        }

        if(flag){
            int k = pos0;
            ans = min(ans, min(k, n-k+2));
        }

        flag = true;
        for(int i = 0; i < n; i++){
            int exp = (pos0 - i + n) % n;
            if(nums[i] != exp){
                flag = false;
                break;
            }
        }

        if(flag){
            int k = (n - 1 - pos0 + n) % n;
            ans = min(ans, 1 + min(k, n-k));
        }
        return ans==1e9 ? -1 : ans;
    }
};