class Solution {
public:
    int passwordStrength(string password) {
        //unordered_map<int, int> mp1;
        unordered_map<char, int> mp;
        int p = 0;
        for(char c : password){
            if(mp[c] > 0){
                continue;
            }
            else if(islower(c)){
                mp[c]++;
                p += 1;
            }
            else if(isupper(c)){
                mp[c]++;
                p += 2;
            }
            else if(isdigit(c)){
                mp[c]++;
                p += 3;
            }
            else{
                mp[c]++;
                p += 5;
            }
        }
        return p;
    }
};