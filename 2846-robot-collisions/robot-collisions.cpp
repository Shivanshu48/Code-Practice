class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i++)
        {
            idx[i] = i;
        }

        sort(idx.begin(), idx.end(),
        [&](int a, int b)
        {
            return positions[a] < positions[b];
        });

        stack<int> st;
        for(int id : idx)
        {
            if(directions[id] == 'R')
            {
                st.push(id);
            }
            else
            {
                while(!st.empty() && healths[id] > 0)
                {
                    int top = st.top();

                    if(healths[top] > healths[id])
                    {
                        healths[top]--;
                        healths[id] = 0;
                    }
                    else if(healths[top] < healths[id])
                    {
                        healths[id]--;
                        healths[top] = 0;
                        st.pop();
                        continue;
                    }
                    else
                    {
                        healths[id] = 0;
                        healths[top] = 0;
                        st.pop();
                    }

                    break;
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(healths[i] > 0)
            {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};