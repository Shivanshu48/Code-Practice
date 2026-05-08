class Solution {
public:
    vector<bool> isPrime;
    void build(int maxVal){
        isPrime.assign(maxVal + 1, true);

        if(maxVal >= 0){
            isPrime[0] = false;
        }

        if(maxVal >= 1){
            isPrime[1] = false;
        }

        for(int i = 2; i * i <= maxVal; i++){
            if(isPrime[i]){
                for(int j = i * i; j <= maxVal; j += i){
                    isPrime[j] = false;
                }
            }
        }
    }
    
    int minJumps(vector<int>& nums){
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        int maxEl = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl, nums[i]);
        }
        build(maxEl);

        queue<int> que;
        vector<bool> visited(n, false);
        que.push(0);
        visited[0] = true;

        unordered_set<int> seen;
        int steps = 0;
        while(!que.empty()){
            int size = que.size();
            
            while(size--){
                int i = que.front();
                que.pop();

                if(i == n-1) {
                    return steps;
                }

                if(i-1 >= 0 && !visited[i-1]){
                    que.push(i-1);
                    visited[i-1] = true;
                }

                if(i+1 <= n-1 && !visited[i+1]){
                    que.push(i+1);
                    visited[i] = true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])){
                    continue;
                }

                for(int multiple = nums[i]; multiple <= maxEl; multiple += nums[i]){
                    if(!mp.contains(multiple)){
                        continue;
                    }
                    for(int &j : mp[multiple]) {
                        if(!visited[j]) {
                            que.push(j);
                            visited[j] = true;
                        }
                    }
                }
                seen.insert(nums[i]);
            }
            steps++;
        }
        return steps;
    }
};