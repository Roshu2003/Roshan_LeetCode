class Solution {
public:
    vector<int> dp;

    int solve(int sum) {
        if(sum == 0) return 0;

        if(dp[sum] != -1) return dp[sum];

        int ans = INT_MAX;

        for(int i = 1; i * i <= sum; i++) {
            ans = min(ans, 1 + solve(sum - i * i));
        }

        return dp[sum] = ans;
    } // O(nsqrt(n))

    int numSquares(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};