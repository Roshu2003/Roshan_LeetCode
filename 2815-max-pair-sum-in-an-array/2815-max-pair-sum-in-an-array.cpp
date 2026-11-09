class Solution {
public:
    int find(int n){
        int mx = 0;
        while(n > 0){
            int x = n %  10;
            n /= 10;
            mx = max(mx,x);
        }
        return mx;
    }
    int maxSum(vector<int>& nums) {
        map<int,int> mp;
        int ans = -1;
        for(auto it : nums){
            int x = find(it);
            if(mp.count(x)){
                ans = max(ans,mp[x] + it);
            }
            mp[x] = max(mp[x],it);
        }
        return ans;
    }
};