class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(),nums.end());
        int ans = mx * k;
        int n = k - 1;
        ans += n * (n + 1) / 2;
        return ans;
    }
};