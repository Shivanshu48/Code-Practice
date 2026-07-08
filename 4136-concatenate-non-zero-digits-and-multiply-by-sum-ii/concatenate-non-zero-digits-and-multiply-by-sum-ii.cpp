class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> digits;
        vector<int> positions;
        for(int i = 0; i < n; i++){
            if(s[i] != '0'){
                digits.push_back(s[i] - '0');
                positions.push_back(i);
            }
        }
        
        int m = digits.size();
        if(m == 0){
            return vector<int>(queries.size(), 0);
        }
        
        vector<ll> pow10(m + 1, 1);
        for(int i = 1; i <= m; ++i){
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        vector<ll> prefSum(m + 1, 0);
        for(int i = 0; i < m; i++){
            prefSum[i + 1] = prefSum[i] + digits[i];
        }
        
        vector<ll> prefVal(m + 1, 0);
        for(int i = 0; i < m; i++){
            prefVal[i + 1] = (prefVal[i] * 10 + digits[i]) % MOD;
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for(const auto& q : queries){
            int L = q[0], R = q[1];
            
            auto it1 = lower_bound(positions.begin(), positions.end(), L);
            auto it2 = upper_bound(positions.begin(), positions.end(), R);
            
            if(it1 == positions.end() || it1 >= it2){
                answer.push_back(0);
                continue;
            }
            
            int idx1 = distance(positions.begin(), it1);
            int idx2 = distance(positions.begin(), it2) - 1;
            
            int count = idx2 - idx1 + 1;
            ll current_sum = prefSum[idx2 + 1] - prefSum[idx1];
            ll x = (prefVal[idx2 + 1] - (prefVal[idx1] * pow10[count]) % MOD + MOD) % MOD;
            ll res = (x * current_sum) % MOD;
            answer.push_back(res);
        }
        
        return answer;
    }
};