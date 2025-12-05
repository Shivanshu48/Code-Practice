class Solution {
public:
    vector<int> parent, rank;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int px=find(x), py=find(y);
        if(px==py) return;
        if(rank[px]>rank[py]) parent[py]=px;
        else if(rank[px]<rank[py]) parent[px]=py;
        else parent[px]=py, rank[py]++;
    }
    long long countPairs(int n, vector<vector<int>>& edges){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto &e:edges) Union(e[0], e[1]);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[find(i)]++;
        long long res=0, rem=n;
        for(auto &p:mp){
            long long sz=p.second;
            res+=sz*(rem-sz);
            rem-=sz;
        }
        return res;
    }
};
