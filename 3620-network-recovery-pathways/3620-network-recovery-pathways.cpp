class Solution {
public:
#define P pair<long long, int>
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int hi = 0;
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, wt});
                hi = max(hi, wt);
            }
        }
        int lo = 0;
        int ans = -1;
        auto check = [&](int mid) {
            vector<long long> dist(n, 1e18);
            priority_queue<P, vector<P>, greater<P>> pq;
            pq.push({0, 0});
            dist[0] = 0;
            while (!pq.empty()) {
                auto [cost, node] = pq.top();
                pq.pop();
                if (cost > dist[node]) continue;
                if(node == n - 1 && cost <= k)return true;
                for (auto [it, w] : adj[node]) {
                    if (w >= mid && (w + cost < dist[it])) {
                        dist[it] = w + cost;
                        pq.push({dist[it], it});
                    }
                }
            }
            return dist[n - 1] <= k;
        };
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};