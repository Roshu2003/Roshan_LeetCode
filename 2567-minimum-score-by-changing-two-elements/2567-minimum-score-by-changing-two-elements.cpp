class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int x = nums.back() - nums[2];
        int y = nums[n - 3] - nums[0];
        int z = nums[n - 2] - nums[1];
        return min({x,y,z});
    }
};