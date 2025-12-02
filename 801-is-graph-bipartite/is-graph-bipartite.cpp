class Solution {
public:
    int N;
    bool checkBiparDFS(vector<vector<int>>& adj, int curr, vector<int>& color, int currColor){
        color[curr] = currColor;
        for(int &v : adj[curr]){
            if(color[v] == color[curr]){
                return false;
            }
            if(color[v] == -1){
                int colorV = 1-currColor;
                if(checkBiparDFS(adj, v, color, colorV) == false){
                    return false;
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
                if(checkBiparDFS(graph, i, color, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};