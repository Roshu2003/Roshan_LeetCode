typedef long long ll;
class Solution {
public:

    ll paths(int m, int n, vector<string>& grid){//# of path from (0,0) to (n - 1,m - 1);
        vector<vector<ll>> dp(m,vector<ll>(n,0));
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='#'){
                    dp[i][j] = 0;
                    continue;
                }

                if(i) dp[i][j] += dp[i-1][j];
                if(j) dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
    vector<string> createGrid(int m, int n, int k) {
        vector<string> grid(m, string(n, '.'));

        ll init = paths(m,n,grid);
        if(init==k) return grid;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = '#';
                ll p = paths(m,n,grid);
                if(p==k) return grid;
                else if(p<k) grid[i][j] = '.';
            }
        }
        
        return {};
    }
};