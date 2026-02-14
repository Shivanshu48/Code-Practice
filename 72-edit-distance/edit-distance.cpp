class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> t(m+1, vector<int>(n+1));
        for(int i = 0; i < m+1; i++){
            for(int j = 0; j < n+1; j++){
                if(i == 0 || j == 0){
                    t[i][j] = i+j;
                }

                else if(word1[i-1] == word2[j-1]){
                    t[i][j] = t[i-1][j-1];
                }
                else{
                    int ins = 1 + t[i][j-1];
                    int del = 1 + t[i-1][j];
                    int rep = 1 + t[i-1][j-1];
                    t[i][j] = min({ins, del, rep});
                }
            }
        }
        return t[m][n];
    }
};