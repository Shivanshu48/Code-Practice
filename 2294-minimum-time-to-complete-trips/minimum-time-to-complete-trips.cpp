class Solution {
public:
    long long numberOfTrips(vector<int>& time, long long mid){
        long long  sum = 0;
        for(auto& i : time){
            sum += (long long)(mid/i);
        }
        return sum;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long low = 0;
        long long high = 1e14;
        
        long long ans;
        while(low <= high){
            long long mid = low + (high-low)/2;
            auto tottrips = numberOfTrips(time, mid);
            if(tottrips >= totalTrips){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};