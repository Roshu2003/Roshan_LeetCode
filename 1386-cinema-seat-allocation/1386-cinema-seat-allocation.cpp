class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        map<int,int> mp;
        for(auto it : nums){
            int r = it[0];
            int c = it[1];
            if(c > 1 && c < 10){
                mp[r] |= (1 << (c - 2));
            }
        }
        int ans = (n - mp.size()) * 2;
        int l = 0b00001111;
        int m = 0b00111100;
        int r = 0b11110000;

        for(auto [it,msk] : mp){
            int left = (l & msk) == 0;
            int mid = (m & msk) == 0;
            int right = (r & msk) == 0;
            if(left && right){
                ans += 2;
            }
            else if(left || right || mid){
                ans++;
            }
        }
        return ans;
    }
};