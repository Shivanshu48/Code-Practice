class Solution {
public:
    int sumele(int n){
        int sum = 0;
        while(n != 0){
            int d  = n%10;
            sum += d;
            n = n / 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int x : nums){
            int i = sumele(x);
            mini = min(mini, i);
        }
        return mini;
    }
};