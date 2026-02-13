class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c;
        int i = 0,j = 0;
        while(i < nums1.size() || j < nums2.size()){
            if(j == nums2.size() || (i < nums1.size() && nums1[i] < nums2[j])){
                c.push_back(nums1[i++]);
            }
            else{
                c.push_back(nums2[j++]);
            }
        }
        int n = c.size();
        if(n % 2 == 1){
            return c[n/2];
        }
        return (c[n/2-1] + c[n/2]) / 2.0;
    }
};