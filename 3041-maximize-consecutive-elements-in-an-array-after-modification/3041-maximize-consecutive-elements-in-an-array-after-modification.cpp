class Solution {
public:
    vector<int> v;
    int n;
    vector<unordered_map<int,int>> dp;
    int solve(int i,int prev){
        if(i >= n)return 0;
        if(dp[i].count(prev))return dp[i][prev];
        int nottake = solve(i + 1,prev);
        int take = 0;
        if(prev == -1 || v[i] == prev + 1){
            take = max(take,1 + solve(i + 1,v[i]));
        }
        if(prev == -1 || v[i] + 1 == prev + 1){
            take = max(take,1 + solve(i + 1,v[i] + 1));
        }
        return dp[i][prev] = max(take,nottake);
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // v = nums;
        // n =  v.size();
        // dp.resize(n);
        // return solve(0,-1);
        unordered_map<int, int> dp1;
        int ans = 0;
        for (int x : nums) {
            dp1[x + 1] = dp1[x] + 1;
            dp1[x] = dp1[x - 1] + 1;
            ans = max({ans, dp1[x], dp1[x + 1]});
        }
        return ans;
    }
};