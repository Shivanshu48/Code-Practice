class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        int n = intervals.size(); 
        
        int count = 0;
        int i = 1;
        vector<int> lastInterval = intervals[0];
        while(i < n){
            int curr_end   = intervals[i][1];
            int curr_start = intervals[i][0];
            
            int last_end = lastInterval[1];
            
            if(curr_start >= last_end){
                lastInterval = intervals[i];
            } 
            else if(curr_end >= last_end){
                count++;
            } 
            else if(curr_end < last_end){
                lastInterval = intervals[i]; 
                count++;
            }
            
            i++;
        }
        return count;
    }
};