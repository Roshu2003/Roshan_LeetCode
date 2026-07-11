class Solution {
public:
    pair<int, int> dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;

        int nodes = 1;               
        int edges = adj[node].size();
        for (auto it : adj[node]) {
            if (!vis[it]) {
                auto [childNodes, childEdges] = dfs(it, vis, adj);
                nodes += childNodes;
                edges += childEdges;
            }
        }

        return {nodes, edges};
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                auto [cnt,ed] = dfs(i, vis, adj);
                // cout<<cnt<<" "<<ed<<endl;
                ed /= 2;
                if (cnt * (cnt - 1) == 2 * ed)
                    ans++;
            }
        }
        return ans;
    }
};
// 6