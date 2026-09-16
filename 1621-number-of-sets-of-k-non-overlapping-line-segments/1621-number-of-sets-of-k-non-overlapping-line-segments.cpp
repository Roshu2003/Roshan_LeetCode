class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    long long modPow(long long a, long long b) {
        long long result = 1;

        while (b > 0) {
            if (b & 1) result = result * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        return result;
    }

    int numberOfSets(int n, int k) {
        if (k > n - 1) return 0;

        int top = n + k - 1;
        vector<long long> fact(top + 1, 1);

        for (int i = 1; i <= top; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        long long denominator =
            fact[2 * k] * fact[top - 2 * k] % MOD;

        long long inverseDenominator = modPow(denominator, MOD - 2);

        return fact[top] * inverseDenominator % MOD;
    }
};