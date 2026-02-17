class Solution {
public:
    
    void solve(string &s, int i, vector<string>& currpath, vector<vector<bool>>& t, vector<vector<string>>& res){
        if(i == s.length()){
            res.push_back(currpath);
            return; 
        }

        for(int j = i; j < s.length(); j++){
            if(t[i][j] == true){
                currpath.push_back(s.substr(i, j-i+1));
                solve(s, j+1, currpath, t, res);
                currpath.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            t[i][i] = true;
        }
        for(int L = 2; L <= n; L++){
            for(int i = 0; i < n-L+1; i++){
                int j = i+L-1;
                if(s[i] == s[j]){
                    if(L == 2){
                        t[i][j] = true;
                    }
                    else{
                        t[i][j] = t[i+1][j-1];
                    }
                }
            }
        }

        vector<vector<string>> res;
        vector<string> currpath;
        solve(s, 0, currpath, t, res);
        return res;
    }
};