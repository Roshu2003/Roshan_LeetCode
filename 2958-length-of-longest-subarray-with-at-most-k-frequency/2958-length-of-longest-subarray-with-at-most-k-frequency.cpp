class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int st = 0;
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            while(mp[nums[i]] > k){
                if(--mp[nums[st]] == 0){
                    mp.erase(nums[st]);
                }
                st++;
            }
            ans = max(ans,i - st + 1);
        }
        return ans;
    }
};