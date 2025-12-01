class Solution {
public:
    bool possible(long long t, int n, vector<int>& batteries){
        long long tot = 0;
        for(int i=0; i<batteries.size(); i++){
            long long curr = batteries[i];
            if(curr < t){
                tot += curr;
            }
            else{
                tot += t;
            }
        }
        if(tot >= t*n) return true;
        else return false;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int i=0; i<batteries.size(); i++){
            sum += batteries[i];
        }

        long long l = 0, r = sum;
        long long ans = 0;

        while(l <= r){
            long long mid = l+(r-l)/2;
            if(possible(mid, n ,batteries)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};