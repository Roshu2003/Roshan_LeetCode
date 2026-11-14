class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> v((2050 - 1950) + 1,0);
        for(auto it : logs){
            int l = it[0];
            int r = it[1];
            v[l - 1950]++;
            v[r - 1950]--;
        }
        int n = 2050 - 1950;
        for(int i = 1; i <= n; i++)v[i] += v[i - 1];
        int mx = 0;
        int ans = -1;
        for(int i = 0; i <= n; i++){
            if(v[i] > mx){
                mx =v[i];
                ans = i + 1950;
            }
        }
        return ans;
    }
};