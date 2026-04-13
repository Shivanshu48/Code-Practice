class Solution {
public:
    bool isPrime(int n){
        if(n < 2) return false;
        int c = 1;
        if(n == 2 || n == 3) return true;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int s = nums.size();
        int op = 0;
        for(int i = 0; i < s; i++){
            if(i % 2 == 0 && (isPrime(nums[i]) == false)){
                while(isPrime(nums[i]) != true){
                    nums[i]++;
                    op++;
                }
            }

            if(i % 2 != 0 && (isPrime(nums[i]) == true)){
                while(isPrime(nums[i]) != false){
                    nums[i]++;
                    op++;
                }
            }
        }
        return op;
    }
};