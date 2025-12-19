class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r = n-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            int missing = arr[mid] - (mid+1);

            if(missing < k){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return k+l;
    }
};