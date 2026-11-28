class Solution {
public:
    vector<int> sz;
    int dfs(int node,vector<vector<int>>& adj){
        int s = 1;
        for(auto it : adj[node]){
            s += dfs(it,adj);
        }
        sz[node] = s;
        return s;
    }
    int countHighestScoreNodes(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[p[i]].push_back(i);
        }
        sz.resize(n,0);
        dfs(0,adj);
        map<long long,int> mp;
        for(int i = 0; i < n; i++){
            int size = sz[i];
            long long score = 1;
            int rem = n - size;
            if(rem > 0)score *= rem;
            for(auto it : adj[i]){
                score *= sz[it];
            }
            mp[score]++;
        }
        return mp.rbegin()->second;
    }
};