class Solution {
public:
    int minimumDifference(vector<int>& nums){
        int n = nums.size();
        int half = n / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        vector<vector<int>> leftSums(half + 1), rightSums(half + 1);
        for(int mask = 0; mask < (1 << half); mask++){
            int sum = 0, cnt = 0;
            for(int i = 0; i < half; i++){
                if(mask & (1 << i)){
                    sum += left[i];
                    cnt++;
                }
            }
            leftSums[cnt].push_back(sum);
        }

        for(int mask = 0; mask < (1 << half); mask++){
            int sum = 0, cnt = 0;
            for(int i = 0; i < half; i++){
                if (mask & (1 << i)) {
                    sum += right[i];
                    cnt++;
                }
            }
            rightSums[cnt].push_back(sum);
        }

        for(int i = 0; i <= half; i++){
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int ans = INT_MAX;
        for(int i = 0; i <= half; i++){
            for(int s1 : leftSums[i]){
                int need = (totalSum / 2) - s1;
                auto &vec = rightSums[half - i];

                auto it = lower_bound(vec.begin(), vec.end(), need);
                if(it != vec.end()){
                    int s2 = *it;
                    ans = min(ans, abs(totalSum - 2 * (s1 + s2)));
                }
                if(it != vec.begin()){
                    --it;
                    int s2 = *it;
                    ans = min(ans, abs(totalSum - 2 * (s1 + s2)));
                }
            }
        }
        return ans;
    }
};