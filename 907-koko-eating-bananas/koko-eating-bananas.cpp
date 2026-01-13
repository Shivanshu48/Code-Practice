class Solution {
public:
    int totalcapacity(vector<int>& piles, int mid, int h){
        int  sumhours = 0;
        for(auto& i : piles){
            sumhours += i/mid;
            if(i%mid != 0){
                sumhours++;
            }
        }
        return sumhours <= h;
    }

    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        while(l < r){
            int mid = l + (r-l)/2;
            if(totalcapacity(piles, mid, h)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};