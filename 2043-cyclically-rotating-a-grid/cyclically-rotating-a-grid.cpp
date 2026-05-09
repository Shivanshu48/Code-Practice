class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int totLayer = min(rows, cols) / 2;

        for(int layer = 0; layer < totLayer; layer++){
            int top = layer;
            int left = layer;
            int bottom = rows-layer-1;
            int right = cols-layer-1;

            vector<int> temp;

            for(int col = left; col <= right; col++){
                temp.push_back(grid[top][col]);
            }

            for(int row = top + 1; row < bottom; row++){
                temp.push_back(grid[row][right]);
            }

            for(int col = right; col >= left; col--){
                temp.push_back(grid[bottom][col]);
            }

            for(int row = bottom - 1; row > top; row--){
                temp.push_back(grid[row][left]);
            }

            int size = temp.size();
            int shift = k % size;
            vector<int> rotated(size);

            for(int i = 0; i < size; i++){
                rotated[i] = temp[(i + shift) % size];
            }

            int idx = 0;
            for(int col = left; col <= right; col++){
                grid[top][col] = rotated[idx++];
            }

            for(int row = top + 1; row < bottom; row++){
                grid[row][right] = rotated[idx++];
            }

            for(int col = right; col >= left; col--){
                grid[bottom][col] = rotated[idx++];
            }

            for(int row = bottom - 1; row > top; row--){
                grid[row][left] = rotated[idx++];
            }
        }
        return grid;
    }
};