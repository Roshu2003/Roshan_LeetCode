class Solution {
public:
    long long dfs(int i,int j,vector<vector<int>> & grid,vector<vector<int>> &vis){
        long long sum = grid[i][j];
        vis[i][j] = 1;
        int dx[] = {0,1,-1,0};
        int dy[] = {-1,0,0,1};
        int n = grid.size();
        int m = grid[0].size();
        for(int k = 0; k < 4;k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc]  != 0){
                sum += dfs(nr,nc,grid,vis);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans =0 ;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0 ; i < n; i++){
            for(int j =0 ; j < m; j++){
                if(grid[i][j] != 0 && !vis[i][j]){
                    long long sum = dfs(i,j,grid,vis);
                    if(sum % k == 0)ans++;
                }
            }
        }
        return ans;
    }
};