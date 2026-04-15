class Solution {
public:
    int dp[21][21];
    bool solve(int i, int j, string s, string p){
        if(j == p.length()){
            if(i == s.length())return true;
            else return false;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool fcm = false;
        if(i < s.length() && (p[j] == s[i] || p[j] == '.')){
            fcm = true;
        }

        if(p[j+1] == '*'){
            bool skip = solve(i, j+2, s, p);
            bool take = fcm && solve(i+1, j, s, p);
            return dp[i][j] = skip || take;
        }
        else{
            return dp[i][j] = fcm && solve(i+1, j+1, s, p);
        }
    }
    
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};