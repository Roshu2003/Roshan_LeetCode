class Solution {
public:
    int stoneGameVIII(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] += nums[i - 1];
        }
        vector<long long> dp(n,0);
        function<int(int)> solve = [&](int i) -> int {
            if(i == n - 1)return nums[i];
            if(dp[i] != LLONG_MIN)return dp[i];
            int take = nums[i] - solve(i + 1);
            int nottake = solve(i + 1);
            return dp[i] = max(take, nottake);
        };
        // return solve(1);
        dp[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 1; i--){
            int take = nums[i] - dp[i + 1];
            int nottake = dp[i + 1];
            dp[i] = max(take,nottake);
        }
        return dp[1];
    }
};