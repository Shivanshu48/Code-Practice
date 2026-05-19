class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size();
        int n = nums2.size();
        int l = max(m, n);
        int i1 = 0, i2 = 0;
        int ans = -1;
        while(i1 < m && i2 < n){
            if(nums1[i1] == nums2[i2]){
                ans = nums1[i1];
                break;
            }
            else if(nums1[i1] < nums2[i2]) i1++;
            else i2++;
        }
        return ans;
    }
};