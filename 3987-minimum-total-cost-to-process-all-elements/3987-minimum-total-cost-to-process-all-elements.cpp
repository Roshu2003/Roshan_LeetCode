class Solution {
public:
    long long modmul(long long a, long long b, long long mod) {
        long long result = 0;
        a %= mod;
        while (b > 0) {
            if (b & 1) {
                result = (result + a) % mod;
            }
            a = (a + a) % mod;
            b >>= 1;
        }

        return result;
    }
    int minimumCost(vector<int>& nums, int k) {
        int mod = 1e9 + 7;
        long long sum = k;
        long long ans = 0;
        long long cnt = 1;
        long long inv2 = (mod + 1) / 2;
        for (auto it : nums) {
            if (sum - it >= 0) {
                sum -= it;
            } else {
                int n = (it - sum) / k + ((it - sum) % k != 0);
                sum += n * k;
                long long add = modmul(n,cnt,mod) + modmul(n,(n - 1),mod) * inv2 % mod;
                ans = (ans + add) % mod;
                cnt = (cnt + n);
                sum -= it;
            }
        }
        return ans;
    }
};
// n / 2 *(2 * cnt + (n - 1)) = 3 * 4 = 12)
// n * cnt + n * (n - 1) / 2;