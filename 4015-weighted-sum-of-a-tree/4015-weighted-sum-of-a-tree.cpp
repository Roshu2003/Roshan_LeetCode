class Solution {
public:
    long long weightedSum(vector<int>& p, vector<int>& nums) {
        long long ans = 0;
        for(auto it : nums)ans += it;
        int n = p.size();
        long long sum = ans;
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            adj[i].push_back(p[i]);
            adj[p[i]].push_back(i);
        }
        // for(auto it : adj){
        //     for(auto i: it)cout<<i<<" ";
        //     cout<<endl;
        // }
        queue<int> q;
        q.push(0);
        int d = 1;
        vector<int> vis(n,0);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop();
                vis[node] = 1;
                ans -= nums[node] * 1LL *  d;
                for(auto it : adj[node]) if(!vis[it])q.push(it);
            }
            d++;
        }
        // cout<<d<<endl;
        ans += sum * 1LL * (d - 1);
        return ans;
    }
};