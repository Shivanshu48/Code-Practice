class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> v;
        for(int i = 0;i < n; i++)
            v.push_back({(double) wage[i] / quality[i], quality[i]});
        sort(v.begin(), v.end());

        priority_queue<int> pq;
        int sum = 0;
        double res = 1e14;
        for(auto &[ratio, q] : v){
            pq.push(q);
            sum += q;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                res = min(res, ratio*sum);
            }
        }
        return res;
    }
};