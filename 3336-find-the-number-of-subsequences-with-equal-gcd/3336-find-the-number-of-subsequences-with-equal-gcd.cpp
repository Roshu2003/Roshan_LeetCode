class Solution {
public:
    // int dp[201][201];
    int n;
    vector<int> v;
    int mod = 1e9 + 7;
    // int solve(int i,int g1,int g2){
    //     if(i >= n){
    //         return g1 == g2;
    //     }
    //     if(dp[i][g1][g2] != -1)return dp[i][g1][g2];
    //     int x = v[i];
    //     int A = solve(i + 1,gcd(g1,x),g2) % mod;
    //     int B = solve(i + 1,g1,gcd(g2,x)) % mod;
    //     int C = solve(i + 1,g1,g2) % mod;
    //     return dp[i][g1][g2] = ((A + B) % mod + C) % mod;
    // }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        v = nums;
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,0) - 1;
        vector<vector<int>> dp(201, vector<int>(201, 0));
        dp[0][0] = 1;
        for (auto x : nums) {
            vector<vector<int>> ndp(201, vector<int>(201, 0));
            for (int g1 = 0; g1 <= 200; g1++) {
                for (int g2 = 0; g2 <= 200; g2++) {
                    if (dp[g1][g2] == 0)
                        continue;
                    int val = dp[g1][g2];

                    ndp[g1][g2] = (ndp[g1][g2] + val) % mod;
                    ndp[gcd(g1, x)][g2] = (ndp[gcd(g1, x)][g2] + val) % mod;
                    ndp[g1][gcd(g2, x)] = (ndp[g1][gcd(g2, x)] + val) % mod;
                }
            }
            dp = ndp;
        }
        long long ans = 0;

        for (int g = 1; g <= 200; g++) {
            ans = (ans + dp[g][g]) % mod;
        }

        return ans;
    }
};