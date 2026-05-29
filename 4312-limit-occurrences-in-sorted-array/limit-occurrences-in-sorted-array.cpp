class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int x : nums){
            if(mp[x] >= k){
                mp[x]++;
                continue;
            }
            else{
                mp[x]++;
                res.push_back(x);
            }
        }
        return res;
    }
};