class Solution {
public:
    int N;
    bool checkBiparBFS(vector<vector<int>>& adj, int curr, vector<int>& color, int currColor){
        queue<int> q;
        q.push(curr);
        color[curr] = currColor;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                if(color[v] == color[u]){
                    return false;
                }
                else if(color[v] == -1){
                    color[v] = 1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        N = graph.size();
        vector<int> color(N, -1);
        for(int i=0; i<N; i++){
            if(color[i] == -1){
                if(checkBiparBFS(graph, i, color, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};