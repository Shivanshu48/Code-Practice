class Solution {
public:
    int countTriples(int n) {
    int c = 0;
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            int s = a*a+b*b;
            int x = sqrt(s);
            if(x <= n && x*x == s) c++;
        }
    }
    return c;
    }
};