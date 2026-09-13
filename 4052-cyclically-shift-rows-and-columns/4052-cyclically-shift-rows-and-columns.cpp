class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& row, vector<int>& col) {
        for(int i = 0; i < row.size(); i++){
            rotate(grid[i].begin(),grid[i].begin() + row[i],grid[i].end());
        }
        for(int i = 0; i < col.size(); i++){ // 0 1
            vector<int> c(n,0);
            for(int j = 0; j < n; j++){ // 0 1
                int pos = (j - col[i] + n) % n; // (1 - 0) % 2 = 1;
                // cout<<pos<<endl;
                c[pos] = grid[j][i]; // 1 0
                cout<<grid[j][i]<<" "<<pos<<endl; // 
            }
            for(int j = 0; j < n; j++){
                grid[j][i] = c[j];
            }
        }
        return grid;
    }
};