class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = s.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
        }
        function<void(int, vector<int>&)> dfs = [&](int node, vector<int>& pos) {
            int idx = s[node] - 'a';
            int old = pos[idx];
            pos[idx] = node;
            for (auto it : adj[node]) {
                int id = s[it] - 'a';
                if (pos[id] != -1) {
                    p[it] = pos[id];
                }
                dfs(it, pos);
            }
            pos[idx] = old;
        };
        vector<int> pos(26, -1);
        dfs(0, pos);
        // adj.clear();
        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; i++) {
            newAdj[p[i]].push_back(i);
        }
        vector<int> ans(n, 0);
        function<int(int)> solve = [&](int node)-> int{
            int sz = 1;
            for (auto it : newAdj[node]) {
               sz += solve(it);
            }
           return ans[node] = sz;
        };
        solve(0);
        return ans;
    }
};