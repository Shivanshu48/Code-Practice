class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> cost(2*limit+2, 0);
        for(int i = 0; i < n / 2; i++){
            int x = nums[i];
            int y = nums[n-1-i];

            int low = min(x, y) + 1;
            int high = max(x, y) + limit;

            cost[2] += 2;
            cost[2*limit+1] -= 2;

            cost[low] -= 1;
            cost[high+1] += 1;

            cost[x+y] -= 1;
            cost[x+y+1] += 1;
        }

        int ans = INT_MAX;
        for(int s = 2; s <= 2 * limit; s++){
            cost[s] += cost[s-1];

            ans = min(ans, cost[s]);
        }
        return ans;
    }
};