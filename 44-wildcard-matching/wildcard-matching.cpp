class Solution {
public:
    int t[2001][2001];
    bool solve(string &s, string &p, int i, int j){
        if(j == p.length()){
            return i == s.length();
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        bool fcm = false;
        if(i < s.length() && s[i] == p[j] || p[j] == '?'){
            fcm = true;
        }

        if(p[j] == '*'){
            bool skip = solve(s, p, i, j+1);
            bool take = (i < s.length()) && solve(s, p, i+1, j);
            return t[i][j] = take || skip;
        }
        else{
            return t[i][j] = fcm && solve(s, p, i+1, j+1);
        }
        return t[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        memset(t, -1, sizeof(t));
        return solve(s, p, 0, 0);
    }
};