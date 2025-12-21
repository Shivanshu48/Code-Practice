class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int x : nums){
            k += x;
        }

        if(k <= 1) return 0;

        int curr = 0;
        for(int i=0; i<k; i++){
            curr += nums[i];
        }

        int maxOnes = curr;

        for(int i=k; i<n+k; i++){
            curr += nums[i%n];
            curr -= nums[(i-k)];
            maxOnes = max(maxOnes, curr);
        }

        return k - maxOnes;
    }
};