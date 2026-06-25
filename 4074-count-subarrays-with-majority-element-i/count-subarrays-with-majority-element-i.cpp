class Fenwick {
public:
    vector<long long> bit;
    int n;

    Fenwick(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long query(int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> comp = pref;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        Fenwick bit(comp.size());

        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;

            ans += bit.query(idx - 1);

            bit.update(idx, 1);
        }

        return ans;
    }
};