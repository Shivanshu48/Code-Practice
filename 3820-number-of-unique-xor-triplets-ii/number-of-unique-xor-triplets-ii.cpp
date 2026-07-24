class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s1;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                s1.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> s2;
        for(int pairX : s1){
            for(int &num : nums){
                s2.insert(pairX ^ num);
            }
        }
        return s2.size();
    }
};