class Solution {
public:
    int smallestNumber(int n, int t) {
        int i = 0;
        int res;
        bool found = true;
        while(found){
            int copy = n + i;
            int c = copy;
            int pro = 1;
            while(copy != 0){
                int d = copy % 10;
                pro *= d;
                copy /= 10; 
            }
            if(pro % t == 0){
                found = false;
                res = c;
                break;
            }
            else{
                i++;
            }
        }
        return res;
    }
};