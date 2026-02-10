class Solution {
public:
    int n; 
    int t[1001][1001];
    bool isPre(string& prev, string& curr){
        int M = prev.length();
        int N = curr.length();
        if(M >= N || N-M != 1){
            return false;
        }
        int i = 0, j = 0;
        while(i < M && j < N){
            if(prev[i] == curr[j]){
                i++;
            }
            j++;
        }
        return i == M;
    }

    static bool check(string& word1, string& word2){
        return word1.length() < word2.length();
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(words.begin(), words.end(), check);
        vector<int> t(n, 1);
        int maxl = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPre(words[j], words[i])){
                    t[i] = max(t[i], t[j]+1);
                    maxl = max(maxl, t[i]);
                }
            }
        }
        return maxl;
    }
};