class Solution {
public:
    int n;
    vector<vector<int>> v;
    long long dp[100005][4][4];
    long long solve(int i,int prevL,int prevR){
        if(i == n / 2)return 0;
        if(dp[i][prevL + 1][prevR + 1] != -1)return dp[i][prevL + 1][prevR + 1];
        long long ans = LLONG_MAX;
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 3; b++){
                if(a == b || a == prevL || b == prevR)continue;
                long long curr = v[i][a] + v[n - 1 - i][b] + solve(i + 1,a,b);
                ans = min(ans,curr);
            }
        }
        return dp[i][prevL + 1][prevR + 1] = ans;
    }
    long long minCost(int n_, vector<vector<int>>& cost) {
        n = n_;
        v = cost;
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,-1);
    }
};