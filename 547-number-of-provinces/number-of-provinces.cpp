class Solution {
public:

    int V;
    void DFS(unordered_map<int, vector<int>> &adj, int node, vector<bool> &vis){
        vis[node] = true;
        for(int u : adj[node]){
            if(!vis[u]){
                DFS(adj, u, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        V = isConnected.size();
        vector<bool> vis(V, false);

        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                count++;
                DFS(adj, i, vis);
            }
        }
        return count;
    }
};