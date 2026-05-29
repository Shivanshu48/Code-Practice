class Solution {
public:
    long long power(long long a, int k, long long limit){
        if(a == 0) return 0;
        long long res = 1;
        while(k--){
            if(res > limit/a){
                return limit+1;
            }
            res *= a;
        }
        return res;
    }
    long long kthRootFloor(long long n, int k){
        long long low = 0, high = 1e9;
        long long ans = 0;
        while(low <= high){
            long long mid = low + (high-low)/2;

            if(power(mid, k, n) <= n){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
    int countKthRoots(int l, int r, int k){
        long long right = kthRootFloor(r, k);
        long long left = (l == 0 ? 0 : kthRootFloor(l - 1, k));
        long long ans = right - left;
        if(l == 0) ans++;
        return ans;
    }
};