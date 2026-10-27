class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string>v(n,string(m,'#'));
        for(int j = 0; j < m; j++)v[0][j] = '.';
        for(int i = 0; i < n; i++)v[i][m - 1] = '.';
        return v;
    }
};