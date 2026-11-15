class Solution {
public:
    int minimumPossibleSum(int n, int t) {
        const long long mod = 1e9 + 7;
        const long long inv2 = 500000004;

        if (n == 1) return 1;
        long long ans = 0;
        long long cnt = (t - 1) / 2;
        if (n <= cnt) {
            ans = (n * 1LL * (n + 1) % mod * inv2) % mod;
        }
        else {
            long long m = n - cnt;
            long long a = t;
            if (t % 2 == 0) {
                m--;
                ans = t / 2;
            }
            long long temp = (cnt * (cnt + 1) % mod * inv2) % mod;
            long long rem = (m % mod * ((2LL * a + m - 1) % mod) % mod * inv2) % mod;
            ans = (ans + temp) % mod;
            ans = (ans + rem) % mod;
        }
        return ans;
    }
};