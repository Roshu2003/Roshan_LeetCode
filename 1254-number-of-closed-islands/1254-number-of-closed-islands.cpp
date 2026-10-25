class Solution {
public:
    vector<vector<int>> vis,grid;
    int n,m;
    void dfs1(int i,int j){
        vis[i][j] = 1;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int k = 0; k < 4; k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 0){
                dfs(nr,nc);
                grid[nr][nc] = 1;
            }
        }
    }
    void dfs(int i ,int j){
        vis[i][j] = 1;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int k = 0; k < 4; k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 0){
                dfs(nr,nc);
            }
        }
    }
    int closedIsland(vector<vector<int>>& v) {
        n = v.size();
        m = v[0].size();
        vis.assign(n,vector<int>(m,0));
        grid = v;
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0){
                dfs1(i,0);
            }
            if(grid[i][m - 1] == 0)dfs1(i,m - 1);
        }
        for(int j = 0; j < m ;j++){
            if(grid[0][j] == 0)dfs1(0,j);
            if(grid[n - 1][j] == 0)dfs1(n - 1,j);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};