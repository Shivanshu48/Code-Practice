class Solution {
    public int findMin(int[] nums) {
        int low = 0;
        int high = nums.length - 1;
        
        while (low <= high) {
            int mid = (low+high)/2;
            if(mid != 0 && nums[mid]<nums[mid-1]) {
                return nums[mid];
            }
            
            else if(high-low+1 == 1){
                return nums[low];
            }
            else if(nums[mid]>nums[high]){
                low = mid+1;
            }

            else{
                high = mid-1;
            }
                
        }
        return nums[(high-low)+1];
    }
}