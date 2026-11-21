class Solution {
public:
    int n;
    queue<pair<int, int>> q;
    vector<vector<int>> vis;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> v;
    void dfs(int i, int j) {
        vis[i][j] = 1;
        q.push({i, j});
        for (int k = 0; k < 4; k++) {
            int nr = i + dx[k];
            int nc = j + dy[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && v[nr][nc] == 1 &&
                !vis[nr][nc]) {
                dfs(nr, nc);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        v = grid;
        vis.assign(n, vector<int>(n, 0));
        bool ok = true;
        for (int i = 0; i < n && ok; i++) {
            for (int j = 0; j < n && ok; j++) {
                if (v[i][j] == 1) {
                    dfs(i, j);
                    ok = false;
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = i + dx[k];
                    int nc = j + dy[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        !vis[nr][nc]) {
                        if (v[nr][nc] == 1) {
                            return ans;
                        }
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};