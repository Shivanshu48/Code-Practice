class Solution {
public:
    string frequencySort(string s) {
        typedef pair<char, int> p;

        struct lambda{
            bool operator()(p &P1, p &P2){
                return P1.second < P2.second;
            }
        };

        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }

        priority_queue<p, vector<p>, lambda> pq;
        for(auto &it : mp){
            pq.push({it.first, it.second});
        }

        string ans = "";
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            ans += string(temp.second, temp.first);
        }
        return ans;
    }
};