class Solution {
public:
    int largestAltitude(vector<int>& gain){
        int maxal=0;
        int currgain=0;
        for(int i = 0; i < gain.size(); i++)
        {
            currgain += gain[i];
            maxal = max(maxal, currgain);
        }
        return maxal;
    }
};