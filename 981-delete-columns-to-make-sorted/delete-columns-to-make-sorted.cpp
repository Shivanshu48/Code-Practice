class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();
        int count = 0;

        for(int c=0; c<col; c++){
            for(int r=0; r<row-1; r++){
                if(strs[r][c] > strs[r+1][c]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};