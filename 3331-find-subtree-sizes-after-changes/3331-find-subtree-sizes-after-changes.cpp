class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = s.size();

        vector<vector<int>> tree(n);

        for(int i = 1; i < n; i++){
            tree[p[i]].push_back(i);
        }

        vector<int> newParent(n);

        vector<int> last(26, -1);

        // Step 1: Find new parents
        function<void(int)> dfs = [&](int node) {

            int ch = s[node] - 'a';

            int old = last[ch];

            // closest ancestor with same character
            if(old != -1)
                newParent[node] = old;
            else
                newParent[node] = p[node];

            last[ch] = node;

            for(auto child : tree[node]){
                dfs(child);
            }

            // backtrack
            last[ch] = old;
        };

        dfs(0);


        // Step 2: Build new tree
        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++){
            if(newParent[i] != -1)
                adj[newParent[i]].push_back(i);
        }


        // Step 3: Find subtree sizes
        vector<int> ans(n);

        function<int(int)> sizeDFS = [&](int node) {

            int cnt = 1;

            for(auto child : adj[node]){
                cnt += sizeDFS(child);
            }

            return ans[node] = cnt;
        };

        sizeDFS(0);

        return ans;
    }
};