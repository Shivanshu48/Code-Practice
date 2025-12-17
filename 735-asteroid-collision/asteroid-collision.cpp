class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int a:asteroids){
            bool des = false;

            while(!st.empty() && st.top() > 0 && a < 0){
                if(abs(st.top()) < abs(a)){
                    st.pop();
                    continue;
                }
                else if(abs(st.top()) == abs(a)){
                    st.pop();
                }
                des = true;
                break; 
            }

            if(!des){
                st.push(a);
            }
        }

        vector<int> res(st.size());
        for(int i=st.size()-1; i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};