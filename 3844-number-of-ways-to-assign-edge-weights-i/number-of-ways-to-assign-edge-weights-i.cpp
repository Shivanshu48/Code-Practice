class Solution {
public:
    int M = 1e9+7;
    typedef long long ll;
    ll power(ll base, ll exponent){
        if(exponent == 0){
            return 1;
        }
        ll half = power(base, exponent/2);
        ll result = (half * half) % M;
        if(exponent % 2 == 1){
            result = (result * base) % M;
        }
        return result;
    }
    int depth(unordered_map<int, vector<int>> &adj, int node, int parent){
        int d = 0;
        for(int &n : adj[node]){
            if(n == parent) continue;
            d = max(d, depth(adj, n, node) + 1);
        }
        return d;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int h = depth(adj, 1, -1);
        return power(2, h-1);
    }
};