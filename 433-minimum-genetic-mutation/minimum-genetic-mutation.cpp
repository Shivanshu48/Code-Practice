class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());
        unordered_set<string> vis;
        queue<string> que;

        que.push(startGene);
        vis.insert(startGene);

        int level = 0;
        while(!que.empty()){
            int n = que.size();
            while(n--){
                string curr = que.front();
                que.pop();

                if(curr == endGene){
                    return level;
                }

                for(char c : "ACGT"){
                    for(int i = 0; i < curr.length(); i++){
                        string neigh = curr;
                        neigh[i] = c;

                        if(vis.find(neigh) == vis.end() && bankset.find(neigh) != bankset.end()){
                            vis.insert(neigh);
                            que.push(neigh);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};