class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> fre;
        vector<int> vec;
        for(int num:nums){
            fre[num]++;
        }
        for(auto &it:fre){
            
            if(it.second>n/3){
                vec.push_back(it.first);
            }
        }
        return vec;
    }
};