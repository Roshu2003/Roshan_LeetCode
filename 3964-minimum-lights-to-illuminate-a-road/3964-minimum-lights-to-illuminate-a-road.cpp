class Solution {
public:
    int minLights(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1,0);
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)continue;
            int l = max(0,i - nums[i]);
            int r = min(n - 1,i + nums[i]);
            pre[l]++;
            pre[r + 1]--;
        }
        for(auto i = 1; i < n + 1; i++){
            pre[i] += pre[i - 1];
        }
        // for(auto it : pre)cout<<it<<" ";
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < pre.size() - 1; i++){
            if(pre[i] == 0){
                cnt++;
            }
            else{
                if(cnt != 0)
                ans += (cnt - 1) / 3 + 1;
                cnt = 0;
            }
        }
        if(cnt != 0)
        ans += (cnt - 1) / 3 + 1;
        return ans;
    }
};