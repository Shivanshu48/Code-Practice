class Solution {
public:
    bool canRepair(vector<int>& ranks, long long time, int cars){
        long long repaired = 0;
        for(int rank : ranks){
            repaired += (long long)sqrt(time/rank);
            if(repaired >= cars) return true;
        }
        return false;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0;
        long long r = (long long)*min_element(ranks.begin(), ranks.end()) * cars * cars;
        while(l < r){
            long long midTime = l + (r - l) / 2;
            if(canRepair(ranks, midTime, cars)){
                r = midTime;
            }
            else{
                l = midTime + 1;
            }
        }
        return l;
    }
};