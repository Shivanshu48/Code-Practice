class Solution {
public:
    long long countBadPairs(vector<int>& nums){
        int n = nums.size();
        long long result = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int diff = nums[i] - i;
            int totalPairsTillIndex = i;
            int goodPairs = mp[diff];
            result += (totalPairsTillIndex - goodPairs);
            mp[diff]++;
        }
        return result;
    }
};