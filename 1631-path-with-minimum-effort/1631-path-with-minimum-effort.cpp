class Solution {
public:
    vector<vector<int>> v;
    int n, m;
    int ans = INT_MAX;
    void solve(int i, int j,int sum) {
        if (i >= n || j >= m)
            return;
        if (i == n - 1 && j == m - 1) {
            ans = min(ans,sum);
            return;
        }
        int x = v[i][j];
        v[i][j] = -1;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int nr = i + dx[k];
            int nc = j + dy[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] != -1) {
                int newSum = max(sum, abs(x - v[nr][nc]));
                solve(nr, nc,newSum);
            }
        }
        v[i][j] = x;
    }
    using T = pair<int,pair<int,int>>;
    int minimumEffortPath(vector<vector<int>>& v_) {
        v = v_;
        n = v.size();
        m = v[0].size();
        // solve(0, 0,0);
        // return ans;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<T,vector<T>,greater<T>> pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto [cost,pos] = pq.top();
            pq.pop();
            int i = pos.first;
            int j = pos.second;
            if(i == n - 1 && j == m - 1)return cost;
            if(cost > dist[i][j])continue;
            int dx[] = {0,1,0,-1};
            int dy[] = {1,0,-1,0};
            for(int k = 0; k < 4; k++){
                int nr = i + dx[k];
                int nc = j + dy[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int newCost = max(cost,abs(v[i][j] - v[nr][nc]));
                    if(newCost < dist[nr][nc]){
                        dist[nr][nc] = newCost;
                        pq.push({newCost,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};