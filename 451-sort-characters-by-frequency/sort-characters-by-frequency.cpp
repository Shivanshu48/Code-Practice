class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c:s) freq[c]++;
        int n=s.size();
        vector<string> bucket(n+1);
        for(auto&p:freq){
            bucket[p.second].append(p.second,p.first);
        }
        string ans;
        for(int i=n;i>=1;i--){
            ans+=bucket[i];
        }
        return ans;
    }
};