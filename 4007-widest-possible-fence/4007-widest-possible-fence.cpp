class Solution {
public://1 2 3 4 5 7
    int maximumWidth(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it :nums)mp[it]++;
        vector<int> v;
        for(auto it : mp)v.push_back(it.first);
        unordered_map<long long,int> p;

        for(int i = 0; i  < v.size(); i++){
            for(int j = i; j < v.size(); j++){
                long long sum = v[i] + v[j];
                // cout<<sum<<" "<<i<<" "<<j<<endl;
                if(i == j){
                    p[sum] += mp[v[i]] / 2;
                }
                else{
                    p[sum] += min(mp[v[i]],mp[v[j]]);
                }
            }
        }
        // for(auto [it,cnt] : p)cout<<it<<" "<<cnt<<endl;
        int ans = 0;
        for(auto &[h,cnt] : p){
            ans = max(ans,cnt + mp[h]);
        }
        for(auto &[it,cnt] : mp)ans = max(ans,cnt);
        return ans;
    }
};