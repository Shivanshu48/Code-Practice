class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWat=0;
        int lp=0, rp=height.size()-1;
        while(lp < rp){
            int w = rp-lp;
            int ht = min(height[lp], height[rp]);
            int currWat = w*ht;
            maxWat = max(maxWat, currWat);

            height[lp]<height[rp]? lp++ : rp--;
        }
        return maxWat;
    }
};