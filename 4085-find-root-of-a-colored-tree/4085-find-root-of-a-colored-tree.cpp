class Solution {
public:
    int find(char c) {
        if (c == 'R')
            return 0;
        else if (c == 'B')
            return 1;
        return 2;
    }
    int findColoredRoot(vector<vector<int>>& edges, string col) {
        int n = col.size();
        vector<int> ind(n,0),out(n,0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int cu = find(col[u]);
            int cv = find(col[v]);

            if(cu == cv)return -1;

            if((cu + 1) % 3 == cv){
                out[u]++;
                ind[v]++;
            }
            else{
                out[v]++;
                ind[u]++;
            }
        }
        int root = -1;
        for(int i = 0; i < n; i++){
            if(out[i] > 2)return -1;
            if(ind[i] == 0){
                if(root != -1) return -1;
                root = i;
            }else if(ind[i] != 1) return -1;
        }
        return root;
    }
};