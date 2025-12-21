class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n, 0);
        int prevTime = 0;

        for(string log : logs){
            int id, time;
            string type;
            stringstream ss(log);
            string temp;

            getline(ss, temp, ':');
            id = stoi(temp);
            getline(ss, type, ':');
            getline(ss, temp, ':');
            time = stoi(temp);

            if(type == "start"){
                if(!st.empty()){
                    ans[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } 
            else{
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time+1;
            }
        }
        return ans;
    }
};