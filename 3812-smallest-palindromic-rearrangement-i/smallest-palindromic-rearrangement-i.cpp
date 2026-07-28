class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(char c : s){
            freq[c - 'a']++;
        }

        string fh = "";
        char mid = '\0';

        for(int i = 0; i < 26; i++){
            char ch = 'a' + i;
            if(freq[i] % 2 != 0){
                mid = ch;
            }
            fh.append(freq[i]/2, ch);
        }

        string sh = fh;
        reverse(sh.begin(), sh.end());

        if(mid != '\0'){
            return fh + mid + sh;
        }
        return fh + sh;
    }
};