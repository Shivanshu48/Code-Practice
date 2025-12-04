class Solution {
public:
    vector<int> parent, rank;
    int find(int i, vector<int>& parent){
        if(i == parent[i]){
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }
    
    void Union(int x, int y, vector<int>&parent, vector<int>& rank){
        int xparent = find(x, parent);
        int yparent = find(y, parent);
        if(xparent == yparent){
            return;
        }
        
        if(rank[xparent] > rank[yparent]){
            parent[yparent] = xparent;
        }
        else if(rank[xparent] < rank[yparent]){
            parent[yparent] = xparent;
        }
        else{
            parent[xparent] = yparent;
            rank[yparent]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }

        int components = n;
        for(auto& vec : connections){
            if(find(vec[0], parent) != find(vec[1], parent)){
                Union(vec[0], vec[1],parent, rank);
                components--;
            }
        }
        return components-1;
    }
};