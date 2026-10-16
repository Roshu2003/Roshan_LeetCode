
class Solution {
public:
    using ll = long long;
    static const int MOD = 1e9 + 7;

    int n;
    vector<ll> sqSum, sum, lz;

    void lzAdd(int i, int l, int r, ll val) {
        ll len = r - l + 1;
        ll oldSum = sum[i];

        sqSum[i] = (
            sqSum[i]
            + 2LL * val % MOD * oldSum % MOD
            + len % MOD * val % MOD * val % MOD
        ) % MOD;

        sum[i] = (oldSum + len % MOD * val % MOD) % MOD;
    }

    void push(int i, int l, int r) {
        if (lz[i] == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        ll val = lz[i];

        lzAdd(2 * i + 1, l, mid, val);
        lzAdd(2 * i + 2, mid + 1, r, val);

        lz[2 * i + 1] = (lz[2 * i + 1] + val) % MOD;
        lz[2 * i + 2] = (lz[2 * i + 2] + val) % MOD;

        lz[i] = 0;
    }

    void updateRange(int start, int end, int i,
                     int l, int r, ll val) {
        if (l > end || r < start)
            return;

        if (start <= l && r <= end) {
            lzAdd(i, l, r, val);
            lz[i] = (lz[i] + val) % MOD;
            return;
        }

        push(i, l, r);

        int mid = l + (r - l) / 2;

        updateRange(start, end, 2 * i + 1,
                    l, mid, val);

        updateRange(start, end, 2 * i + 2,
                    mid + 1, r, val);

        sum[i] = (sum[2 * i + 1] +
                  sum[2 * i + 2]) % MOD;

        sqSum[i] = (sqSum[2 * i + 1] +
                    sqSum[2 * i + 2]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sqSum.assign(4 * n, 0);
        sum.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        vector<int> lastSeen(100001, -1);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int start = lastSeen[nums[i]] + 1;

            updateRange(start, i, 0, 0, n - 1, 1);

            ans = (ans + sqSum[0]) % MOD;

            lastSeen[nums[i]] = i;
        }

        return ans;
    }
};
