class Solution {
public:
    bool canJump(vector<int>& stones, int maxJump, int n){
        if(stones[1] - stones[0] > maxJump) return false;

        for(int i = 2; i < n; i++){
            if(stones[i] - stones[i - 2] > maxJump){
                return false;
            }
        }
        return true;
    }

    int maxJump(vector<int>& stones){
        int n = stones.size();
        if(n <= 3) return stones[n-1] - stones[0];
        int l = 1;
        int r = stones[n-1];

        while(l < r){
            int mid = l + (r - l)/2;
            if(canJump(stones, mid, n)){
                r = mid;
            } 
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};