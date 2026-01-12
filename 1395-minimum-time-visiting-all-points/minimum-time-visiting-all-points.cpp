class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totaltime = 0;
        for(int i = 1; i < points.size(); i++){
            int distonx = abs(points[i][0] - points[i-1][0]);
            int distony = abs(points[i][1] - points[i-1][1]);
            
            totaltime += max(distonx, distony);
        }
        return totaltime;
    }
};