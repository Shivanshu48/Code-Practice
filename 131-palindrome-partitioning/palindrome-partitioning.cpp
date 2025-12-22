class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;

    bool isPalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(int idx, string &s){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<s.size(); i++){
            if(isPalindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i-idx+1));
                solve(i+1, s);
                temp.pop_back();
            }
        }
    }

    
    vector<vector<string>> partition(string s){
        solve(0, s);
        return ans;
    }
};