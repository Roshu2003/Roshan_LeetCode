class Solution {
public:
    vector<vector<int>> adj;
    vector<int>op,sc;
    int dfs(int node){
        if(adj[node].empty()){
            return sc[node];
        }

        int total = sc[node];
        int mn = INT_MAX;
        for(auto it : adj[node]){
            int val = dfs(it);
            total += val;
            mn = min(mn,val);
        }

        if(op[node] == 1){
            return total - mn;
        }
        return total - min(0,mn);
    }
    int maxScore(vector<int>& p, vector<int>& op1, vector<int>& score) {
        op = op1;
        sc = score;
        int n = p.size();
        adj.resize(n);
        for(int i = 1; i < n; i++){
            adj[p[i]].push_back(i);
        }
        return dfs(0);
    }
};