class Solution {
public:
    
    bool isValid(vector<int>& nums, int exp_max, int n){
        vector<long long> arr(begin(nums), end(nums));
        
        for(int i=0; i<n-1; i++){
            if(arr[i] > exp_max){
                return false;
            }
            long long buffer = exp_max - arr[i];
            arr[i+1] -= buffer; 
        }
        return arr[n-1] <= exp_max;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int maxl = 0;
        int maxr = *max_element(begin(nums), end(nums));

        while(maxl <= maxr){
            int mid_max = maxl + (maxr- maxl)/2;
            if(isValid(nums, mid_max, n)){
                res = mid_max;
                maxr = mid_max-1;
            }
            else{
                maxl = mid_max+1;
            }
        }
        return res;
    }
};