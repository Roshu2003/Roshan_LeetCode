class Solution {
public:
    vector<int> nums;
    map<vector<int>, int> dp;
    bool solve(int i, int j, int f, int sum) {
        auto key = {i, j, f, sum};
        if (i > j)
            return sum > 0;
        if (dp.count(key))
            return dp[key];
        bool first = false;
        bool second = false;
        if (f) {
            first = solve(i + 1, j, 0, sum + nums[i]);
            second = solve(i, j - 1, 0, sum + nums[j]);
        } else {
            first = solve(i + 1, j, 1, sum - nums[i]);
            second = solve(i, j - 1, 1, sum - nums[j]);
        }
        return dp[key] = first || second;
    }
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();

        // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
        int dp[N + 2][N + 2];
        memset(dp, 0, sizeof(dp));

        for (int size = 1; size <= N; ++size)
            for (int i = 0, j = size - 1; j < N; ++i, ++j) {
                int parity = (j + i + N) % 2; // j - i - N; but +x = -x (mod 2)
                if (parity == 1)
                    dp[i + 1][j + 1] = max(piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
                else
                    dp[i + 1][j + 1] = min(-piles[i] + dp[i + 2][j + 1],-piles[j] + dp[i + 1][j]);
            }

        return dp[1][N] > 0;
    }
};