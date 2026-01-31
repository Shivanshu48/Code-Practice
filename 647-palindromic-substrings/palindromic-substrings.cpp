class Solution {
public:
    int countSubstrings(string s){
        int n=s.size(),cnt=0;

        for(int c=0;c<2*n;c++){
            int l=c/2;
            int r=l+c%2;
            while(l>=0 && r<n && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
        }
        return cnt;
    }
};