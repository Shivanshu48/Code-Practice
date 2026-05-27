class Solution {
public:
    int numberOfSpecialChars(string word){
        vector<int> ll(26, -1);
        vector<int> fu(26, -1);

        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(islower(c)){
                ll[c - 'a'] = i;
            }
            else{
                int idx = tolower(c) - 'a';
                if(fu[idx] == -1){
                    fu[idx] = i;
                }
            }
        }
        int count = 0;

        for(int i = 0; i < 26; i++){
            if(ll[i] != -1 && fu[i] != -1 && ll[i] < fu[i]){
                count++;
            }
        }
        return count;
    }
};