class Solution {
public:
    using T = tuple<int, int, int>;
    int minCost(vector<int>& st, vector<int>& ed, vector<int>& rowCosts,
                vector<int>& colCosts) {
        int n = rowCosts.size();
        int m = colCosts.size();
        // vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        // dist[st[0]][st[1]] = 0;
        // priority_queue<T,vector<T>,greater<T>> pq;
        // pq.push({0,st[0],st[1]});
        // while(!pq.empty()){
        //     auto [cost,i,j] = pq.top();
        //     pq.pop();
        //     if(cost > dist[i][j])continue;
        //     if(j - 1 >= 0){
        //         if(dist[i][j - 1] > cost + colCosts[j - 1]){
        //             dist[i][j - 1] = cost + colCosts[j - 1];
        //             pq.push({dist[i][j - 1],i,j - 1});
        //         }
        //     }
        //      if(j + 1 < m){
        //         if(dist[i][j + 1] > cost + colCosts[j + 1]){
        //             dist[i][j + 1] = cost + colCosts[j + 1];
        //             pq.push({dist[i][j + 1],i,j + 1});
        //         }
        //     }
        //      if(i - 1 >= 0){
        //         if(dist[i - 1][j] > cost + rowCosts[i - 1]){
        //             dist[i - 1][j] = cost + rowCosts[i - 1];
        //             pq.push({dist[i - 1][j],i - 1,j});
        //         }
        //     }
        //      if(i + 1 < n){
        //         if(dist[i + 1][j] > cost + rowCosts[i + 1]){
        //             dist[i + 1][j] = cost + rowCosts[i + 1];
        //             pq.push({dist[i + 1][j],i + 1,j});
        //         }
        //     }
        // }
        // return dist[ed[0]][ed[1]];
        int ans = 0;

        // Move horizontally
        int startCol = st[1];
        int endCol = ed[1];

        if(startCol < endCol) {
            for(int j = startCol + 1; j <= endCol; j++) {
                ans += colCosts[j];
            }
        }
        else {
            for(int j = startCol - 1; j >= endCol; j--) {
                ans += colCosts[j];
            }
        }

        // Move vertically
        int startRow = st[0];
        int endRow = ed[0];

        if(startRow < endRow) {
            for(int i = startRow + 1; i <= endRow; i++) {
                ans += rowCosts[i];
            }
        }
        else {
            for(int i = startRow - 1; i >= endRow; i--) {
                ans += rowCosts[i];
            }
        }

        return ans;
    }
};