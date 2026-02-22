class Solution {
public:
    int binaryGap(int n) {
        int lastPos = -1;
        int currPos = 0;
        int maxGap = 0;
        while(n > 0){
            if(n & 1){
                if(lastPos != -1){
                    maxGap = max(maxGap, currPos - lastPos);
                }
                lastPos = currPos;
            }
            currPos++;
            n = n >> 1;
        }
        return maxGap;
    }
};