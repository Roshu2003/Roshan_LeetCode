class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> cnt(n,vector<int>(11,0));
        set<int> st;
        for(auto it : pick){
            int x = it[0];
            int y = it[1];
            cnt[x][y]++;
            int mx = 0;
            for(auto it : cnt[x]){
                mx = max(mx,it);
            }
            if(mx > x)st.insert(x);
        }
        return st.size();
    }
};