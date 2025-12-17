class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long num=0;
        long long res = 0;
        char op='+';

        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                num=num*10 + (s[i]-'0');
            }
            if((!isdigit(s[i]) && s[i] != ' ') || i==s.size()-1){
                if(op == '+'){
                    st.push(num);
                }
                else if(op == '-'){
                    st.push(-num);
                }
                else if(op == '*'){
                    long long t = st.top();
                    st.pop();
                    st.push(t*num);
                }
                else if(op == '/'){
                    long long t = st.top();
                    st.pop();
                    st.push(t/num);
                }
                op = s[i];
                num = 0;
            }
        }

        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return (int)res;
    }
};