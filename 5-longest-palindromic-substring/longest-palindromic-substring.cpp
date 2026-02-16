class Solution {
public:
    
    bool solve(int i, int j, string& s){
        if(i >= j){
            return true;
        }
        if(s[i] == s[j]){
            return solve(i+1, j-1, s);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = INT_MIN;
        int sp = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j, s) == true){
                    if((j - i + 1) > maxlen){
                        maxlen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxlen);
    }
};