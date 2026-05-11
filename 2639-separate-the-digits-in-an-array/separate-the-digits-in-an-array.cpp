class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> sep;
        for(int num : nums){
            string s = to_string(num);
            for(char c : s){
                sep.push_back(c - '0');
            }
        }
        return sep;
    }
};