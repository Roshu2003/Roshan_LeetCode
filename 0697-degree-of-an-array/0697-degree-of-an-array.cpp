class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int d = 0;
        for(auto it : nums){
            mp[it]++;
            d = max(d,mp[it]);
        }
        int ans = INT_MAX;
        int n = nums.size();
        mp.clear();
        int st = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            while(mp[nums[i]] == d){
                ans = min(ans,i - st + 1);
                if(--mp[nums[st]] == 0)mp.erase(nums[st]);
                st++;
            }
        }
        return ans;
    }
};