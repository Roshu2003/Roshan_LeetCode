class Solution {
public:
    #define P pair<int,int>
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<P>> adj(n);
        for(auto it:roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            u--;
            v--;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> dist(n,INT_MAX);
        queue<P>q;
        q.push({INT_MAX,0});
        while(!q.empty()){
            auto [cost,node] = q.front();
            q.pop();
            for(auto &[v,w]:adj[node]){
                if(dist[v] > min(cost,w)){
                    dist[v] = min(cost,w);
                    q.push({dist[v],v});
                }
            }
        }
        return dist[n - 1];
    }
};