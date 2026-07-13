typedef long long ll;
class Solution {
public:

    ll paths(int m, int n, vector<vector<char>>& grid){
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
    vector<string> res(vector<vector<char>>& grid){
        vector<string> ans;
        for(auto& row : grid){
            string s = "";
            for(char c : row){
                s += c;
            }
            ans.push_back(s);
        }
        return ans;
    }
    vector<string> createGrid(int m, int n, int k) {
        vector<vector<char>> grid(m, vector<char>(n, '.'));

        ll init = paths(m,n,grid);
        if(init==k) return res(grid);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = '#';
                ll p = paths(m,n,grid);
                if(p==k) return res(grid);
                else if(p<k) grid[i][j] = '.';
            }
        }
        
        return {};
    }
};