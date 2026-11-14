class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> pre(10, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < 10; j++) {
                if(pre[j] == 0)continue;
                int last = nums[i] % 10;
                if (gcd(j, last) == 1) {
                    ans += pre[j];
                }
            }
            int f_len = log10(nums[i]);
            int x = pow(10, f_len);
            int first = nums[i] / x;
            pre[first]++;
        }
        return ans;
    }
};