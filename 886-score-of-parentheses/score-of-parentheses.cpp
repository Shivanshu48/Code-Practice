class Solution {
public:
    int scoreOfParentheses(string s) {
        int c = 0, score = 0;
        for (int i=0; i<s.size(); i++){
            if(s[i] == '('){
                c++;
            } 
            else{
                c--;
                if(s[i-1] == '('){
                    score += 1<<c;
                }
            }
        }
        return score;
    }
};