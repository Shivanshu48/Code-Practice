class Solution {
public:
    vector<int> sequentialDigits(int low, int high){
        vector<int> res;
        string digits = "123456789";
        
        for(int length = 2; length <= 9; length++){
            for(int startIdx = 0; startIdx <= 9 - length; startIdx++){
                string sub = digits.substr(startIdx, length);
                int num = stoi(sub);
                if(num >= low && num <= high){
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};