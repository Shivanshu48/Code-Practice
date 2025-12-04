class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i, vector<int>& parent){
        if(i == parent[i]){
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int xparent = find(x, parent);
        int yparent = find(y, parent);
        if(xparent == yparent){
            return;
        }

        if(rank[xparent] > rank[yparent]){
            parent[yparent] = xparent;
        }
        else if(rank[xparent] < rank[yparent]){
            parent[xparent] = yparent;
        }
        else{
            parent[xparent] = yparent;
            rank[yparent]++;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i=0; i<26; i++){
            parent[i] = i;
        }

        for(string &s : equations){
            if(s[1] == '='){
                Union(s[0]-'a', s[3]-'a', parent, rank);
            }
        }

        for(string &s : equations){
            if(s[1] == '!'){
                char first = s[0];
                char second = s[3];

                int parentfirst = find(first - 'a', parent);
                int parentsecond = find(second - 'a', parent);
                
                if(parentfirst == parentsecond){
                    return false;
                }
            }
        }
        return true;
    }
};