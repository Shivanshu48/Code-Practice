class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0; 
        int r = 0;
        int jump = 0;
        while(r < n-1){
            int maxjump = 0;
            for(int ind = l; l <= r; l++){
                maxjump = max(maxjump, l + nums[l]);
            }
            l = r+1;
            r = maxjump;
            jump++;
        }
        return jump;
    }
};