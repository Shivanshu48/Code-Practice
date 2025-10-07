class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> fre;
        for(int val : nums){
            fre[val]++;
            if(fre[val]>n/2){
                return val;
            }
        }
        return -1;
    }
};