class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> arr;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(begin(arr) , end(arr));
        int res = arr[0] % x;
        for(int i : arr){
            if(i % x != res){
                return -1;
            }
        }
        int s = arr.size();
        int c = 0;
        int mid = arr[s/2];
        for(int i : arr){
            c = c + abs(i - mid)/x;
        }
        return c;
    }
};