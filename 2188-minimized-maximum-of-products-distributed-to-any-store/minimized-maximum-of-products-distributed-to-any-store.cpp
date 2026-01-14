class Solution {
public:
    bool canDistribute(vector<int>& quantities, int mid, int n){
        long long needStores = 0;
        for(int q : quantities){
            needStores += (q + mid - 1) / mid;
            if(needStores > n) return false;
        }
        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(),quantities.end());
        while(left < right){
            int mid = left + (right - left)/2;
            if(canDistribute(quantities, mid, n)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};