class Solution {
public:
    bool can(long long t, int h, vector<int>& w)
    {
        long long total = 0;
        for (long long wt : w)
        {
            long long x = sqrt((2.0 * t) / wt + 0.25) - 0.5;
            total += x;
            if (total >= h) return true;
        }
        return false;
    }
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 1;
        long long r = 1e16;
        while (l < r)
        {
            long long mid = l + (r - l) / 2;
            if (can(mid, mountainHeight, workerTimes))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};