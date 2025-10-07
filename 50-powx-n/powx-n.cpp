class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;
        
        long binf = n;

        if(n < 0){
            x = 1 / x;
            binf = -binf;
        }
        double ans = 1;
        while(binf > 0){
            if(binf % 2 == 1){
                ans = ans * x;

            }
            x = x * x;
            binf = binf / 2;
        }
        return ans;
    }
};