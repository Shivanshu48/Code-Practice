class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> h, v;

        for(int i = 0; i < hFences.size(); i++){
            for(int j = i + 1; j < hFences.size(); j++){
                h.insert(hFences[j] - hFences[i]);
            }
        }

        for (int i = 0; i < vFences.size(); i++){
            for (int j = i + 1; j < vFences.size(); j++){
                v.insert(vFences[j] - vFences[i]);
            }
        }
        long long side = 0;
        for(int d : h){
            if(v.count(d)){
                side = max(side, (long long)d);
            }
        }

        return side == 0 ? -1 : (side * side) % MOD;
    }
};