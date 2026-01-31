class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;

        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        if(mn==mx) return 0;
        int gap=(mx-mn+n-2)/(n-1);
        vector<int> bmin(n-1,INT_MAX),bmax(n-1,INT_MIN);

        for(int x:nums){
            if(x==mn||x==mx) continue;
            int idx=(x-mn)/gap;
            bmin[idx]=min(bmin[idx],x);
            bmax[idx]=max(bmax[idx],x);
        }

        int ans=0,prev=mn;
        for(int i=0;i<n-1;i++){
            if(bmin[i]==INT_MAX) continue;
            ans=max(ans,bmin[i]-prev);
            prev=bmax[i];
        }
        ans=max(ans, mx-prev);

        return ans;
    }
};