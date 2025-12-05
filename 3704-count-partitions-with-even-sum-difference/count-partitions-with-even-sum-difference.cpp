class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        for(int i=1; i<n; i++){
            nums[i] += nums[i-1];
        }

        for(int i=0; i<n-1; i++){
            if(((nums[n-1] - nums[i]) - nums[i]) % 2 == 0){
                count++;
            }        
        }

        return count;
    }
};