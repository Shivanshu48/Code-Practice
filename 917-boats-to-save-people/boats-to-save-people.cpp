class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0;
        int j = n-1;
        int boat = 0;
        while(i <= j){
            if(people[j] + people[i] <= limit){
                j--;
                i++;
                boat++;
            }
            else{
                j--;
                boat++;
            }
        }
        return boat;
    }
};