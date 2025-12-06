class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int currpresum = 0;
        int c = 0;
        for(int num : nums){
            currpresum += num;
            int reqprefix = currpresum - k;
            if(counts.count(reqprefix)){
                c += counts[reqprefix];
            }
            counts[currpresum]++;
        }
        return c;
    }
};