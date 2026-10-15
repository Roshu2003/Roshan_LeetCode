class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            map<int,int> mp;
            for(auto j = i; j < n; j++){
                mp[nums[j]]++;
                int x = mp.size();
                ans += x * x;
            }
        }
        return ans;
    }
};