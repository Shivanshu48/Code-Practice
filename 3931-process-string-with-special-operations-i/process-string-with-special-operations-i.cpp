class Solution {
public:
    string processStr(string s) {
        string res = "";
        int l = s.length();
        for(int i = 0; i < l; i++){
            if(islower(s[i])){
                res += s[i];
            }
            else if(s[i] == '*'){
                if(res.length() != 0){
                    res.pop_back();
                }
            }
            else if(s[i] == '#'){
                if(res.length() != 0){
                    res += res;
                }
            }
            else if(s[i] == '%'){
                reverse(res.begin(), res.end());
            }
            else{
                continue;
            }
        }
        return res;
    }
};