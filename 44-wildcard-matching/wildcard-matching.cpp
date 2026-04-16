class Solution {
public:
    int t[2001][2001];
    bool solve(int i, int j, string &s, string &p){
        if(j == p.length()){
            return i == s.length();
        }

        if(t[i][j] != -1){
            return t[i][j];
        }
        //if((p.length() == 1 && p[0] == '*') || s.length() == 0) return true;

        bool fcm = false;
        if(i < s.length() && (p[j] == s[i] || p[j] == '?')){
            fcm = true;
        }

        if(p[j] == '*'){
            bool skip = solve(i, j+1, s, p);
            bool take = (i < s.length()) && solve(i+1, j, s, p);
            return t[i][j] = skip || take;
        }
        else{
            return t[i][j] = fcm && solve(i+1, j+1, s, p);
        }
        return t[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, s, p);
    }
};