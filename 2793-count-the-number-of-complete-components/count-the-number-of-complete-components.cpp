class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int comp = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int node_count = 0;
                int edge_count = 0;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    
                    node_count++;
                    edge_count += adj[curr].size();

                    for(int neighbor : adj[curr]){
                        if(!visited[neighbor]){
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                if(edge_count == node_count * (node_count - 1)){
                    comp++;
                }
            }
        }
        return comp;
    }
};