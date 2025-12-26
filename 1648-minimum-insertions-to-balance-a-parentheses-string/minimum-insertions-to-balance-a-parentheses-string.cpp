class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ins = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                open++;
            }
            else{
                if(s[i+1] == ')'){
                    i++;
                }
                else{
                    ins++;
                }
                if(open>0){
                    open--;
                }
                else{
                    ins++;
                }
            }
        }
        ins += open*2;
        return ins;
    }
};