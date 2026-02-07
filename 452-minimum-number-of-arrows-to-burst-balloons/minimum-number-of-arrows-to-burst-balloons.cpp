class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;

        sort(begin(points),end(points));

        int arrows = 1, n = points.size(), i = 0;
        vector<int> lastInterval = points[0];
        while(i < n){
            int curr_start = points[i][0], curr_end = points[i][1];
            int last_end = lastInterval[1];
            if(curr_start > last_end){
                arrows++;
                lastInterval = points[i];
            }
            else if(curr_end < last_end){
                lastInterval = points[i];
            }
            i++;
        }
        return arrows;
    }
};