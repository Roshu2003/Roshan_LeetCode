class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = 0;
        int cnt = 0;
        int zero = 0;
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0){
                zero++;
                continue;
            }
            if(ans == 0){
                ans = nums[i];
            }
            else{
                ans = ans * 1LL * nums[i];
            }
            if (nums[i] < 0) {
                cnt++;
                mx = max(mx, nums[i]);
            }
        }
        int n = nums.size();
        if(cnt == 1){
            if( zero > 0 && zero == n - 1)return 0;
            if(n == 1)
            return ans;
            return ans / mx;
        }
        if(cnt % 2 == 1)
            return ans / mx;
        return ans;
    }
};