class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        int len = s.length();
        vector<int> preSum(len+1,0);
        for(int i = 0; i < len; i++)
        {
            preSum[i+1] = preSum[i] + (s[i]-'0');
        }
        vector<int> divRng;
        int t = len;
        while(t%2 == 0)
        {
            t /= 2;
            divRng.push_back(t);
        }
        if(preSum[len] == 0) return flatCost;

        long long res = (long long)encCost * len * preSum[len];
        vector<long long> pnt;
        for(int i = divRng.size()-1; i >= 0; i--)
        {
            int rng = divRng[i];
            int ind = 0;
            int prv = 0;

            vector<long long> temp;
            int rngInd = 0;

            while(ind+rng <= len)
            {
                int ttlOne = preSum[ind+rng] - prv;
                long long val = (long long)ttlOne * rng * encCost;
                if(ttlOne == 0)
                {
                    val += flatCost;
                }
                long long mn = val;
                if(!pnt.empty())
                {
                    mn = min(mn, pnt[rngInd] + pnt[rngInd+1]);
                }
                temp.push_back(mn);
                rngInd += 2;
                prv = preSum[ind+rng];
                ind += rng;
            }
            pnt=temp;
        }
        if(!pnt.empty())
        {
            res = min(res, pnt[0]+pnt[1]);
        }
        return res;
    }
};