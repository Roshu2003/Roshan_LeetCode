class Solution {
public:
    int dp[201][201][201];
    int n;
    vector<int> v;
    int mod = 1e9 + 7;
    int solve(int i,int g1,int g2){
        if(i >= n){
            return g1 == g2;
        }
        if(dp[i][g1][g2] != -1)return dp[i][g1][g2];
        int x = v[i];
        int A = solve(i + 1,gcd(g1,x),g2) % mod;
        int B = solve(i + 1,g1,gcd(g2,x)) % mod;
        int C = solve(i + 1,g1,g2) % mod;
        return dp[i][g1][g2] = ((A + B) % mod + C) % mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        v = nums;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0) - 1;
    }
};