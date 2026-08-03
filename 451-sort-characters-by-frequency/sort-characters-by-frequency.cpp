class Solution {
public:

    unordered_map<char, int> mp;
    typedef pair<char, int> p;
    vector<p> arr;
    static bool mycomparator(p &p1, p &p2){
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        for(char c : s){
            mp[c]++;
        }

        vector<p> arr(mp.begin(), mp.end());
        sort(arr.begin(), arr.end(), mycomparator);
        string res = "";
        for(auto &it : arr){
            res.append(it.second, it.first);;
        }
        return res;
    }
};