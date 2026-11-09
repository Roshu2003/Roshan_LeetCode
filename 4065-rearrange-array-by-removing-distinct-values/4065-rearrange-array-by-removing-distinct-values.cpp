class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        map<int,int> mp;
        int mx = 0;
        for(auto it : nums){
            mp[it]++;
            mx = max(mx,mp[it]);
        }
        while(mx--){
            for(auto &it : mp){
                if(mp[it.first] > 0)
                    ans.push_back(it.first);
                mp[it.first]--;
            }
        }
        return ans;   
    }
};