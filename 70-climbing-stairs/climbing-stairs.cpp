class Solution {
public:
    int t[45];
    int solve(int i, int n){
        if(i > n) return 0;
        if(i == n) return 1;
        if(t[i] != -1) return t[i];
        int step1 = solve(i+1, n);
        int step2 = solve(i+2, n);
        return t[i] = step1 + step2;
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(0, n);
    }
};