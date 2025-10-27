class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, tot = 0;
        for(int i=0; i<bank.size(); i++){
            int count = 0;
            for(int j=0; j<bank[i].size(); j++){
                if(bank[i][j] == '1') count++;
            }
            if(count > 0){
                tot += prev*count;
                prev = count; 
            }
        }
        return tot;
    }
};