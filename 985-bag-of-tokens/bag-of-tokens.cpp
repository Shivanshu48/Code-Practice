class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if(n < 1) return 0;
        sort(tokens.begin(), tokens.end());
        if(tokens[0] > power) return 0;
        
        int score = 0;
        int maxs = 0;
        int j = n-1;
        int i = 0;
        while(i <= j){
            if(tokens[i] <= power){
                power -= tokens[i];
                score++;
                i++;
                maxs = max(maxs, score);
            }
            else if(score >= 1){
                power += tokens[j];
                j--;
                score--;
            }
            else{
                return maxs;
            }
        }
        return maxs;
    }
};