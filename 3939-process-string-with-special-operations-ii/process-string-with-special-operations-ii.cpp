class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long L = 0;
        for(char &ch : s){
            if(ch == '*'){
                if(L > 0)
                    L--;
            } 
            else if(ch == '#'){
                L *= 2;
            } 
            else if(ch == '%'){
                continue;
            } 
            else{
                L++;
            }
        }
        if(k >= L){
            return '.';
        }
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '*'){
                L++;
            } 
            else if(s[i] == '%'){
                
                k = L - k - 1;
            } 
            else if(s[i] == '#'){
                L = L/2;
                k = (k >= L) ? k - L : k;
            } 
            else{
                L--;
            }
            if(k == L){
                return s[i];
            }
        }
        return '.';

    }
};