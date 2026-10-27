class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int sum) {
        if (sum == 0) return 0;
        if (i * i > sum) return 1e9;

        int &ans = dp[i][sum];
        if (ans != -1) return ans;

        int take = 1 + solve(i, sum - i * i);
        int nottake = solve(i + 1, sum);

        return ans = min(take, nottake);
    }

    int numSquares(int n) {
        dp.assign(sqrt(n) + 2, vector<int>(n + 1, -1));
        return solve(1, n);
    }
};