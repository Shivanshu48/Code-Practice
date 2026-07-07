class Solution {
public:
    long long sumAndMultiply(int n) {
        int copy = n;
        long long sum = 0;
        long long rev = 0;
        while(copy != 0){
            int d = copy % 10;
            if (d != 0) {
                sum += d;
                rev = rev* 10 + d;
            }
            copy /= 10;
        }
        long long x = 0;
        while(rev > 0){
            x = x * 10 + (rev % 10);
            rev /= 10;
        }
        return x * sum;
    }
};