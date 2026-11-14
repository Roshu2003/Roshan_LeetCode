class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& v) {
        map<int,pair<int,int>> mp;
        for(auto it : v){
            int x = it[0];
            int y = it[1];
            mp[x].first++;
            mp[y].second++;
        }
        vector<vector<int>> ans(2);
        for(auto &[x,it] : mp){
            if(it.second == 0)ans[0].push_back(x);
            else if(it.second == 1)ans[1].push_back(x);
            // cout<<x<<" "<<it.second<<endl;
        }
        return ans;
    }
};