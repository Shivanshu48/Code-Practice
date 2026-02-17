class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            t[i][i] = true;
        }
        for(int L = 2; L <= n; L++){
            for(int i = 0; i < n-L+1; i++){
                int j = i+L-1;
                if(s[i] == s[j]){
                    if(L == 2){
                        t[i][j] = (s[i] == s[j]);
                    }
                    else{
                        t[i][j] = ((s[i] == s[j]) && t[i+1][j-1]);
                    }
                }
            }
        }
        vector<int> dp(n);
        for(int i = 0;i < n; i++){
            if(t[0][i] == true){
                dp[i] = 0;
            }
            else{
                dp[i] = INT_MAX;
                for(int k = 0; k < i; k++){
                    if(t[k+1][i] == true && 1+dp[k] < dp[i]){
                        dp[i] = 1+dp[k];
                    }
                }
            }
        }
        return dp[n-1];
    }
};