class Solution {
public:
    int s;
    int dfs(vector<int>& nums, int limit, int pos, vector<int>& memo){
        if(memo[pos] != -1){
            return memo[pos];
        }

        int best = 1;
        for(int step = 1; step <= limit; step++){
            int nextPos = pos + step;

            if(nextPos >= s || nums[nextPos] >= nums[pos]){
                break;
            }

            best = max(best, 1 + dfs(nums, limit, nextPos, memo));
        }

        for(int step = 1; step <= limit; step++){
            int nextPos = pos - step;
            if(nextPos < 0 || nums[nextPos] >= nums[pos]){
                break;
            }
            best = max(best, 1 + dfs(nums, limit, nextPos, memo));
        }
        return memo[pos] = best;
    }

    int maxJumps(vector<int>& arr, int d){
        s = arr.size();
        vector<int> memo(s, -1);
        int answer = 1;
        for(int i = 0; i < s; i++){
            answer = max(answer, dfs(arr, d, i, memo));
        }
        return answer;
    }
};