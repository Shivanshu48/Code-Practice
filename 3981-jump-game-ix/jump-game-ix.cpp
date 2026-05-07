class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxL(n);
        vector<int> minR(n);
        maxL[0] = nums[0];
        minR[n-1] = nums[n-1];

        for(int i = 1; i < n; i++){
            maxL[i] = max(nums[i], maxL[i-1]);
        }

        for(int i = n-2; i > 0; i--){
            minR[i] = min(nums[i], minR[i+1]);
        }
        vector<int> res(n);
        res[n-1] = maxL[n-1];
        for(int i = n-2; i >= 0; i--){
            if(maxL[i] <= minR[i+1]){
                res[i] = maxL[i];
            } 
            else{
                res[i] = res[i+1];
            }
        }
        return res;
    }
};