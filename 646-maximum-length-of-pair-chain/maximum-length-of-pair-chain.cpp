class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> t(n, 1);
        int maxp = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    t[i] = max(t[i], t[j]+1);
                    
                }
            }
            maxp = max(maxp, t[i]);
        }
        return maxp;
    }
};