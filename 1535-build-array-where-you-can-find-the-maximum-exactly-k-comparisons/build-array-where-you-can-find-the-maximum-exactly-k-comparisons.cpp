class Solution {
public:
    int N, M, K;
    int t[51][101][101];
    int mod = 1e9+7;
    int solve(int idx, int searchcost, int maxsofar){
        if(idx == N){
            if(searchcost == K){
                return 1;
            }
            return 0;
        }
        int res = 0;
        if(t[idx][searchcost][maxsofar] != -1){
            return t[idx][searchcost][maxsofar];
        }
        for(int i = 1; i <= M; i++){
            if(i > maxsofar){
                res = (res + solve(idx+1, searchcost+1, i))%mod;
            }
            else{
                res = (res + solve(idx+1, searchcost, maxsofar))%mod;
            }
        }
        return t[idx][searchcost][maxsofar] = res%mod;
    }
    
    int numOfArrays(int n, int m, int k) {
        memset(t, -1, sizeof(t));
        N = n; 
        M = m; 
        K = k;
        return solve(0, 0, 0);
    }
};