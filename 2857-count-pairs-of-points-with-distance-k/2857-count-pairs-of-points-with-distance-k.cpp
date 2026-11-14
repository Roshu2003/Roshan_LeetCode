class Solution {
public:
    int countPairs(vector<vector<int>>& v, int k) {
        unordered_map<int, unordered_map<int, int>> mp;

        int ans = 0;

        for(auto it : v) {
            int x = it[0], y = it[1];

            for(int a = 0; a <= k; a++) {
                int b = k - a;

                int x2 = x ^ a;
                int y2 = y ^ b;

                if(mp.count(x2) && mp[x2].count(y2)) {
                    ans += mp[x2][y2];
                }
            }

            mp[x][y]++;
        }

        return ans;
    }
};