class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        int n  = nums.size();
        map<long long,long long> mp;
        for(auto it:nums){
            map<long long,long long> temp;
            long long x = (it + k) % k;
            temp[x]++;
            for(auto & i:mp){
                long long x = (i.first * 1LL * it + k) % k;
                temp[x] += i.second;
            }
            for(auto it:temp){
                ans[it.first]+= it.second;
            }
            mp = temp;
        }
        return ans;
    }
};