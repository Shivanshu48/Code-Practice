class Solution {
public:
    typedef pair<int, int> p;
    struct lambda{
        bool operator()(p &p1, p &p2){
            return p1.second < p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums){
            mp[x]++;
        }

        priority_queue<p, vector<p>, lambda> pq;
        for(auto &it : mp){
            pq.push({it.first, it.second});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++){
            p temp = pq.top();
            ans.push_back(temp.first);
            pq.pop();
        }
        return ans;
    }
};