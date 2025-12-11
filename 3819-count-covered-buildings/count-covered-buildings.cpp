class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int,int>> row;
        unordered_map<int, pair<int,int>> col;

        for(vector<int> b : buildings){
            int x = b[0], y = b[1];

            if(row.find(x) == row.end()){
                row[x] = make_pair(y, y);
            }
            else{
                if(y < row[x].first){
                    row[x].first = y;
                }
                if(y > row[x].second){
                    row[x].second = y;
                }
            }

            if(col.find(y) == col.end()){
                col[y] = make_pair(x, x);
            }
            else{
                if(x < col[y].first){
                    col[y].first = x;
                }
                if(x > col[y].second){
                    col[y].second = x;
                }
            }
        }

        int covered = 0;

        for(vector<int> b : buildings){
            int x = b[0], y = b[1];

            pair<int,int> r = row[x];
            pair<int,int> c = col[y];

            bool left = y > r.first;
            bool right = y < r.second;
            bool down = x > c.first;
            bool up = x < c.second;

            if(left && right && down && up) covered++;
        }

        return covered;
    }
};