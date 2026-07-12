class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return arr;
        int n = arr.size();
        vector<int> copy(n);
        for(int i = 0; i < n; i++){
            copy[i] = arr[i];
        }
        sort(copy.begin(), copy.end());
        unordered_map<int, int> mp;
        int r = 1;
        mp[copy[0]] = r;
        for(int i = 1; i < copy.size(); i++){
            if(copy[i] != copy[i-1]){
                r++;
            }
            mp[copy[i]] = r;
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};