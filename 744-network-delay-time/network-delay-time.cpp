class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for (auto &it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(n+1, INT_MAX);
        
        result[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &vec : adj[node]){
                
                int adjnode = vec.first;
                int wt = vec.second;
                
                if(d + wt < result[adjnode]){
                    result[adjnode] = d + wt;
                    pq.push({d + wt, adjnode});
                }
                
            }
        }

        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            ans = max(ans, result[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};