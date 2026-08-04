class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        bool present[102] = {false};
        int min_val = nums[0];
        int max_val = nums[0];

        for(int num : nums){
            present[num] = true;
            min_val = std::min(min_val, num);
            max_val = std::max(max_val, num);
        }

        vector<int> missing;
        for(int i = min_val; i <= max_val; i++){
            if(!present[i]){
                missing.push_back(i);
            }
        }

        return missing;
    }
};