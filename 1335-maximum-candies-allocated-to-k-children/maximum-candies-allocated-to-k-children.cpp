class Solution {
public:
    bool maxposs(vector<int>& candies, long long mid, long long k) {
        long long children = 0;

        for(auto &pile : candies){
            children += pile / mid;
            if
            (children >= k) return true;
        }
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 1;
        long long r = *max_element(candies.begin(), candies.end());
        long long ans = 0;

        while(l <= r){
            long long mid = l + (r - l)/2;

            if(maxposs(candies, mid, k)){
                ans = mid;    
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};