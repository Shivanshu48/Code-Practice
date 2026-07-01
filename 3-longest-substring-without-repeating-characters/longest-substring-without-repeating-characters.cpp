class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxLen = 0;
        int left = 0;
        for(int i = 0; i < s.length(); i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= left){
                left = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};