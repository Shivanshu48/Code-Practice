class Solution {
public:
    int n;
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<int> t(n, 1);
        int maxlis = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    t[i] = max(t[i], t[j]+1);
                    maxlis = max(maxlis, t[i]);
                }
            }
        }
        return maxlis;
    }
};