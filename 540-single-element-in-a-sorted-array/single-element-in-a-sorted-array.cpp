class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> fre;
        int ele=0;
        for(int num:nums){
            fre[num]++;
        }
        for(auto &it:fre){
            if(it.second == 1){
                ele = it.first;
            }
        }
        return ele;
    }
};