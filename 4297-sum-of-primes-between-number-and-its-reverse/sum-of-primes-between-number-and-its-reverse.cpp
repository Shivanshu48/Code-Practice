class Solution {
public:
    
    bool isPrime(int num) {
        if(num < 2){
            return false;
        }

        for(int i = 2; i*i <= num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    int sumOfPrimesInRange(int n){
        int rev = 0;
        int val = n;

        while(val > 0){
            rev = rev * 10 + (val % 10);
            val /= 10;
        }

        int left = min(n, rev);
        int right = max(n, rev);
        int total = 0;

        for(int num = left; num <= right; num++){
            if(isPrime(num)){
                total += num;
            }
        }
        return total;
    }
};