class Solution {
public:
    char findKthBit(int n, int k){
        if(n == 1){
            return '0';
        }
        int length = (1 << n) - 1;
        int mid = length / 2 + 1;
        if(k == mid){
            return '1';
        }
        else if(k < mid){
            return findKthBit(n - 1, k);
        }
        else{
            int mirroredIndex = length - k + 1;
            char bit = findKthBit(n - 1, mirroredIndex);
            if(bit == '0'){
                return '1';
            }
            else{
                return '0';
            }
        }
    }
};