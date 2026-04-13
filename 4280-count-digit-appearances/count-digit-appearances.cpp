class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int c = 0;
        for(int x : nums){
            int n = x;
            while(n != 0){
                int d = n % 10;
                if(d == digit) c++;
                n /= 10;
            }
        }
        return c;
    }
};