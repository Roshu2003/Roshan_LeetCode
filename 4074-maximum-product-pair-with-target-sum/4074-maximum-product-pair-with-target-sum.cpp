class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int maxP = INT_MIN;
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x = target - nums[i];
            if (mp.count(x)) {
                int y = nums[i];
                if (x != y && y * x > maxP) {
                    maxP = x * y;
                    if(x > y) ans = {mp[x],i};
                    else ans = {i,mp[x]};
                }
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};