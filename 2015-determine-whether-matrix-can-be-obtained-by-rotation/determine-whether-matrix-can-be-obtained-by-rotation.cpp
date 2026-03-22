class Solution {
public:
    
    bool isEqual(vector<vector<int>>& a, vector<vector<int>>& b){
        int n = a.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] != b[i][j]){
                    return false;
                }
            }
        }
        return true;
    }

    vector<vector<int>> rotate90(vector<vector<int>>& mat){
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                rotated[j][n - 1 - i] = mat[i][j];
            }
        }
        return rotated;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++){
            if(isEqual(mat, target)){
                return true;
            }
            mat = rotate90(mat);
        }
        return false;
    }
};