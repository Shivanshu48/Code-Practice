class Solution {
public:
    int mirrorDistance(int n) {
        int m = n;
        //int j = 0;
        int rev = 0;
        while(m != 0){
            int d = m%10;
            rev = (rev*10)+d;
            m /= 10;
            //j = rev;
        }
        return(abs(n-rev));
    }
};