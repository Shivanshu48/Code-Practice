class Solution {
public:
    int minimumPushes(string word) {
        int n = 0;
        unordered_map<char, int> mp;
        for(char c : word){
            mp[c]++;
        }

        vector<int> freq;
        for(auto &ele : mp){
            freq.push_back(ele.second);
        }
        sort(freq.rbegin(), freq.rend());

        int press = 0;
        for(int i = 0; i < freq.size(); i++){
            int pressPerChar = (i / 8) + 1; 
            press += freq[i] * pressPerChar;
        }
        return press;
    } 
};