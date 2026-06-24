class Solution {
public:
    static const int MOD = 1000000007;
    using ll = long long;

    struct Matrix {
        int n;
        vector<vector<ll>> a;

        Matrix(int n, bool ident = false) : n(n) {
            a.assign(n, vector<ll>(n, 0));
            if (ident) {
                for (int i = 0; i < n; i++) a[i][i] = 1;
            }
        }

        Matrix operator*(const Matrix &other) const {
            Matrix res(n);
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < n; k++) {
                    if (!a[i][k]) continue;
                    ll cur = a[i][k];
                    for (int j = 0; j < n; j++) {
                        if (!other.a[k][j]) continue;
                        res.a[i][j] = (res.a[i][j] + cur * other.a[k][j]) % MOD;
                    }
                }
            }
            return res;
        }
    };

    Matrix power(Matrix base, long long exp) {
        Matrix res(base.n, true);
        while (exp) {
            if (exp & 1) res = res * base;
            base = base * base;
            exp >>= 1;
        }
        return res;
    }
    
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        vector<ll> init(sz);
        for (int i = 0; i < m; i++) {
            init[i] = i;
            init[m + i] = m - 1 - i;
        }

        if (n == 2) {
            ll ans = 0;
            for (ll x : init) ans = (ans + x) % MOD;
            return ans;
        }

        Matrix T(sz);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                T.a[i][m + j] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                T.a[m + i][j] = 1;
            }
        }

        Matrix P = power(T, n - 2);

        vector<ll> finalState(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                finalState[i] = (finalState[i] + P.a[i][j] * init[j]) % MOD;
            }
        }

        ll ans = 0;
        for (ll x : finalState) ans = (ans + x) % MOD;

        return ans;
    }
};