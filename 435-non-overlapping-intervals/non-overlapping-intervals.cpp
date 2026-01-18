class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b){
                 return a[1] < b[1];
             });

        int removals = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < prevEnd){
                removals++;
            } 
            else{
                prevEnd = intervals[i][1];
            }
        }
        return removals;
    }
};