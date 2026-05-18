class Solution {
public:
    int solve(vector<int>& arr, int& n){
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> mp; 
        for(int i = 0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        
        queue<int> que;
        que.push(0);
        vis[0] = true;
        int steps = 0;
        while(!que.empty()) {
            int size = que.size();
            while(size--){
                int curr = que.front();
                que.pop();
                if(curr == n-1) {
                    return steps;
                }
                int left  = curr-1;
                int right = curr+1;
                
                if(left >= 0 && !vis[left]){
                    que.push(left);
                    vis[left] = true;
                }
                
                if(right < n && !vis[right]){
                    que.push(right);
                    vis[right] = true;
                }
                
                for(const int &idx : mp[arr[curr]]){
                    if(!vis[idx]){
                        que.push(idx);
                        vis[idx] = true;
                    }
                }
                mp.erase(arr[curr]);
            }
            steps++;
        }
        return -1;
    }
    int minJumps(vector<int>& arr){
        int n = arr.size();
        if(n == 1){
            return 0;
        }
        return solve(arr, n);
    }
};