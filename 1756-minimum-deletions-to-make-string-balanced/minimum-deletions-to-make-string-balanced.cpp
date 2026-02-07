class Solution {
public:
    int minimumDeletions(string s) {
        int cb = 0,drop = 0;
        for(char c : s){
            if(c == 'b'){
                cb++;
            }
            else{
                drop++;
                drop = min(cb, drop);
            }
        }
        return drop;
    }
};