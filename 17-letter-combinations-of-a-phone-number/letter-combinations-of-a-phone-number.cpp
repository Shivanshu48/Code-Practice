class Solution {
public:
    vector<string> letterCombinations(string digits){
        if (digits.empty()) return {};

        vector<string> result;
        string current;
        vector<string> phone = {
            "",     
            "",     
            "abc", 
            "def", 
            "ghi",  
            "jkl",  
            "mno", 
            "pqrs",
            "tuv",  
            "wxyz" 
        };

        backtrack(digits, 0, phone, current, result);
        return result;
    }

    void backtrack(const string& digits, int index, const vector<string>& phone, string& current, vector<string>& result){

        if(index == digits.size()){
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for(char ch : phone[digit]){
            current.push_back(ch);
            backtrack(digits, index + 1, phone, current, result);
            current.pop_back();
        }
    }
};
