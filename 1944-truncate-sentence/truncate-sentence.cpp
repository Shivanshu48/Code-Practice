class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string word, res = "";
        while(k-- && getline(ss, word, ' ')){
            res += word + " ";
        }
        res.pop_back();
        return res;

    }
};