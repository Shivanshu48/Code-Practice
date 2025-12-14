class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, int> m;
        m["electronics"] = 0;
        m["grocery"] = 1;
        m["pharmacy"] = 2;
        m["restaurant"] = 3;

        vector<pair<int, string>> v;

        for(int i = 0; i < code.size(); i++){
            if(!isActive[i]) continue;
            if(m.count(businessLine[i]) == 0) continue;
            if(code[i].empty()) continue;

            bool ok = true;
            for(char c : code[i]){
                if(!isalnum(c) && c != '_'){
                    ok = false;
                    break;
                }
            }

            if(ok){
                v.push_back({m[businessLine[i]], code[i]});
            }
        }

        sort(v.begin(), v.end(),
             [](const pair<int, string>& a,
                const pair<int, string>& b){
                 if (a.first == b.first)
                     return a.second < b.second;
                 return a.first < b.first;
             });

        vector<string> res;
        for(auto &p : v){
            res.push_back(p.second);
        }

        return res;
    }
};