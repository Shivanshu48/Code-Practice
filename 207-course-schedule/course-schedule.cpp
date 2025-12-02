class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree){
        int count = 0;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int& v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    count++;
                    q.push(v);
                }            
            }
        }
        if(count == n) return true;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses,0);
        for(auto& vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
            
        }
        return topologicalSortCheck(adj, numCourses, indegree);
    }
};