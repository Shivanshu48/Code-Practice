class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<>());
        int amt = 0;
        int c = 0;
        for(int x : cost){
            if(c < 2){
                amt += x;
                c++;
            }
            else{
                c = 0;
                continue;
            }
        }
        return amt;
    }
};