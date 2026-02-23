class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int n = piles.size();
        sort(piles.begin(), piles.end(), greater<int>());
        for(int i = 0; i < n; i++){
            pq.push(piles[i]);
        }

        for(int i = 1; i <= k; i++){
            int x = pq.top();
            pq.pop();
            pq.push(x - floor(x/2));
        }

        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};