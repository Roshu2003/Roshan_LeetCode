class Solution {
public:
    int n, m;
    vector<vector<int>> vis;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void dfs(int i, int j, vector<vector<int>>& grid) {
        vis[i][j] = 1;

        for(int k = 0; k < 4; k++) {
            int nr = i + dx[k];
            int nc = j + dy[k];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               grid[nr][nc] == 0 &&
               !vis[nr][nc]) {

                dfs(nr, nc, grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vis.assign(n, vector<int>(m, 0));

        // Step 1: Mark boundary-connected land

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0 && !vis[i][0])
                dfs(i, 0, grid);

            if(grid[i][m-1] == 0 && !vis[i][m-1])
                dfs(i, m-1, grid);
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 0 && !vis[0][j])
                dfs(0, j, grid);

            if(grid[n-1][j] == 0 && !vis[n-1][j])
                dfs(n-1, j, grid);
        }

        // Step 2: Count remaining islands

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 0 && !vis[i][j]) {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }

        return ans;
    }
};