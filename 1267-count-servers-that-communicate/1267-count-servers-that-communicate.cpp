class Solution {
public:
    int countServers(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans = 0;
        vector<int> row(n,0),col(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == 1){
                    row[i]++;
                    col[j]++;
                    ans++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j =0; j < m ;j++){
                if(v[i][j] == 0)continue;
                if(row[i] <= 1 && col[j] <= 1)ans--;
            }
        }
        return ans;
    }
};