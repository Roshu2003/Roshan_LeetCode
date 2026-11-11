class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> mp;
        int ans = 0;
        int n = nums.size();
        for(auto it : nums)mp[it]++;
        for(auto [it,cnt] : mp){
            ans += cnt / 2;
        }
        return {ans,n - ans * 2};
    }
};