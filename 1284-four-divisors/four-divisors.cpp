class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int n : nums){
            int sum = 1 + n;
            int cnt = 0;
            for(int d = 2; d*d <= n; d++){
                if(n%d == 0){
                    cnt++;
                    sum += d;
                    if(d != n / d){
                        cnt++;
                        sum += n / d;
                    }
                    if(cnt > 2) break;
                }
            }
            if(cnt == 2){
                ans += sum;
            }
        }
        return ans;
    }
};