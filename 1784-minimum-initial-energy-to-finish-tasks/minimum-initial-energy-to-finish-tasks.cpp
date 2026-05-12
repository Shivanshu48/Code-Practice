class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>& a,const vector<int>& b){
            return (a[1]-a[0]) > (b[1]-b[0]);
        }
    };
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp());

        long long cur = 0,res = 0;
        for(auto &t : tasks){
            int en = t[0];
            int need = t[1];
            if(cur < need){
                res += (need - cur);
                cur = need;
            }
            cur -= en;
        }
        return res;
    }
};