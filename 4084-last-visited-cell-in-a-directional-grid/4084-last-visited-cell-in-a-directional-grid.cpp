class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            char ch = grid[r][c];
            grid[r][c] = '.';
            int nr = 0;
            int nc = 0;
            if(ch == 'L'){
                nr = r;
                nc = c - 1;
            }
            else if(ch == 'R'){
                nr = r;
                nc = c + 1;
            }
            else if(ch == 'U'){
                nr = r - 1;
                nc  = c;
            }
            else if(ch == 'D'){
                nr = r + 1;
                nc = c;
            }
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '.'){
                q.push({nr,nc});
                // grid[nr][nc] = '.';
            }
            else return {r,c};
        }
        return {-1,-1};
    }
};