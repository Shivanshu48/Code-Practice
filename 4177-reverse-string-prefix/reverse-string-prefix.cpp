class Solution {
public:
    string reversePrefix(string s, int k) {
        int l=0,r=k-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};