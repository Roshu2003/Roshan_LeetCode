class Solution {
public:
    struct State {
        int x, y, mask;
    };

    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int sx = -1, sy = -1;
        int keyCount = 0;

        // find start and count keys
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    keyCount = max(keyCount, grid[i][j] - 'a' + 1);
                }
            }
        }

        int targetMask = (1 << keyCount) - 1;

        // visited[x][y][mask]
        vector<vector<vector<int>>> vis(
            n, vector<vector<int>>(m, vector<int>(1 << keyCount, 0))
        );

        queue<State> q;
        q.push({sx, sy, 0});
        vis[sx][sy][0] = 1;

        int steps = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto cur = q.front();
                q.pop();

                int x = cur.x;
                int y = cur.y;
                int mask = cur.mask;

                // if all keys collected
                if (mask == targetMask) {
                    return steps;
                }

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    int nmask = mask;

                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;

                    char cell = grid[nx][ny];

                    if (cell == '#') continue; // wall

                    // key
                    if (cell >= 'a' && cell <= 'f') {
                        nmask |= (1 << (cell - 'a'));
                    }

                    // lock
                    if (cell >= 'A' && cell <= 'F') {
                        if (!(mask & (1 << (cell - 'A'))))
                            continue;
                    }

                    if (!vis[nx][ny][nmask]) {
                        vis[nx][ny][nmask] = 1;
                        q.push({nx, ny, nmask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};