class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n);
        maxi[0] = nums[0];
        for(int i = 1; i < n; i++){
            maxi[i] = max(maxi[i-1], nums[i]);
        }

        vector<int> mini(n);
        mini[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            mini[i] = min(nums[i], mini[i+1]);
        }

        int ind = -1;
        int smsofar = INT_MAX;
        for(int i = 0; i < n; i++){
            int curr = maxi[i] - mini[i];
            if(curr <= k && curr < smsofar){
                smsofar = curr;
                ind = i;
                break;
            }
        }
        return ind;
    }
};