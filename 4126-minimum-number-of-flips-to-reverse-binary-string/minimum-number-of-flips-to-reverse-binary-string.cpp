class Solution {
public:
    int minimumFlips(int n) {
        string s;
        while(n > 0){
            s.push_back((n % 2) + '0');
            n /= 2;
        }
        int flips = 0;
        int len = s.size();
        for(int i = 0; i < len/2; i++){
            if(s[i] != s[len - 1 - i]) flips += 2;
        }
        return flips;
    }
};