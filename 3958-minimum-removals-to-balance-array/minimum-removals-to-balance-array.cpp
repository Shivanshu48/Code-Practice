class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int range = 0;
        for(int r = 0; r < n; r++){
            while(nums[r] > 1LL*nums[l]*k){
                l++;
            }
            range = max(range, r-l+1);
        }
        return n - range;
    }
};