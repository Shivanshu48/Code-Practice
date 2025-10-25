class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        return helper(nums, target, st, end);
    }

    int helper(vector<int> nums, int tar, int st, int end){
        if(st <= end){
            int mid = st+(end-st)/2;

            if(nums[mid] == tar){
                return mid;
            }
            else if(nums[mid] <= tar){
                return helper(nums, tar, mid+1, end);
            }
            else{
                return helper(nums, tar, st, mid-1);
            }
        }
        return -1;
    }
};