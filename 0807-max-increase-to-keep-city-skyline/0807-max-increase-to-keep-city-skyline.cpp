class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<int> row(n,0),col(m,0);
        for(int i = 0; i < n; i++){
            int mx = 0;
            for(int j = 0; j < m; j++){
                mx = max(mx,v[i][j]);
            }
            row[i] = mx;
        }
        for(int i = 0; i < m; i++){
            int mx = 0;
            for(int j = 0; j < n; j++){
                mx = max(mx,v[j][i]);
            }
            col[i] = mx;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans +=  min(row[i],col[j]) - v[i][j];
            }
        }
        return ans;
    }
};