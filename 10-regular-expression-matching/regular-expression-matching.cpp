class Solution {
public:
    bool solve(string &s, string &p, int i, int j){
        if(j == p.length()){
            return i == s.length();
        }
        bool fcm = false;

        if(i < s.length() && (s[i] == p[j] || p[j] == '.')){
            fcm = true;
        }

        if(p[j+1] == '*'){
            bool not_take = solve(s, p, i, j+2);
            bool take  = fcm && solve(s, p, i+1, j);
            return take || not_take;
        }
        else{
            return fcm && solve(s, p, i+1, j+1);
        }
    }
    bool isMatch(string s, string p) {
        if(s.length() == 0){
            return true;
        }

        bool check = solve(s, p, 0, 0);
        return check;
    }
};