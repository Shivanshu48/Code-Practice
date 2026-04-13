class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        vector<pair<int, int>> arr;

        int mini = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(target == nums[i]){
                int minsofar = abs(i - start);
                if(minsofar < mini){
                    mini = minsofar;
                }
            }
        }
        return mini;
    }
};