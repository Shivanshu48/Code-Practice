class Solution {
public:
    unordered_map<string, string> memo;

    string solve(string s) {
        if(s.size() <= 2) return s;

        if(memo.count(s)) return memo[s];

        vector<string> blocks;
        int count = 0, start = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') count++;
            else count--;

            if(count == 0) {
                string inner = s.substr(start + 1, i - start - 1);

                string processed =
                    "1" + solve(inner) + "0";

                blocks.push_back(processed);
                start = i + 1;
            }
        }

        sort(blocks.begin(), blocks.end(), greater<string>());

        string result = "";
        for(auto &b : blocks)
            result += b;

        return memo[s] = result;
    }

    string makeLargestSpecial(string s) {
        return solve(s);
    }
};