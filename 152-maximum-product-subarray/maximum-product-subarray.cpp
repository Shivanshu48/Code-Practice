class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevMax = nums[0];
        int prevMin = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            int tempMax = max({curr, curr * prevMax, curr * prevMin});
            int tempMin = min({curr, curr * prevMax, curr * prevMin});
            prevMax = tempMax;
            prevMin = tempMin;
            ans = max(ans, prevMax);
        }
        return ans;
    }
};