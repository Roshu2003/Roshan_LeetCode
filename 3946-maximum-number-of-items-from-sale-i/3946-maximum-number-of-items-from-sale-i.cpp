
class Solution {
public:
    int n, mn;
    vector<int> gain;
    vector<vector<int>> dp;

    const int NEG = -1e9;

    int solve(int idx, int budget, vector<vector<int>>& items) {
        if (idx == n) {
            return budget == 0 ? 0 : NEG;
        }

        if (dp[idx][budget] != -1) {
            return dp[idx][budget];
        }

        int notTake = solve(idx + 1, budget, items);

        int take = NEG;

        int price = items[idx][1];

        if (budget >= price) {
            int next = solve(idx + 1, budget - price, items);

            if (next != NEG) {
                take = gain[idx] + next;
            }
        }

        return dp[idx][budget] = max(take, notTake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();
        mn = INT_MAX;

        gain.resize(n);

        for (int i = 0; i < n; i++) {
            mn = min(mn, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (items[j][0] % items[i][0] == 0) {
                    gain[i]++;
                }
            }
        }

        dp.assign(n, vector<int>(budget + 1, -1));

        int ans = 0;

        for (int spent = 0; spent <= budget; spent++) {
            int val = solve(0, spent, items);
            if (val != NEG) {
                int extra = (budget - spent) / mn;
                ans = max(ans, val + extra);
            }
        }

        return ans;
    }
};
