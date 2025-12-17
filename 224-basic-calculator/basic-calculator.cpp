class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long res = 0, num = 0, sign = 1;

        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i]-'0');
            }

            else if(s[i] == '+' || s[i] == '-'){
                res += sign*num;
                num = 0;
                sign = (s[i] == '+')?1:-1;
            }

            else if(s[i] == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }

            else if(s[i] == ')'){
                res += sign*num;
                num = 0;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        return (int)res+sign*num;
    }
};