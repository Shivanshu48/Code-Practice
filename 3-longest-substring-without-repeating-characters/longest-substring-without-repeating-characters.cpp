class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int l = 0, maxl = 0;
        for(int r=0; r<s.size(); r++){
            char c = s[r];
            if(m.count(c)&&m[c]>=l){
                l = m[c]+1;
            }
            m[c] = r;
            maxl = max(maxl, r-l+1);
        }
        return maxl;
    }
};