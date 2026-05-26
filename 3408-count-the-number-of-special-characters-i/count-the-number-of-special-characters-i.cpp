class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> l;
        unordered_set<char> u;
        for(char c : word){
            if(islower(c)){
                l.insert(c);
            }
            else{
                u.insert(tolower(c));
            }
        }

        int c = 0;
        for(char ch : l){
            if(u.count(ch)) c++;
        }
        return c;
    }
};