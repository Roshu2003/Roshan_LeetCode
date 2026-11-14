class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int mn = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1])continue;
            int diff = abs(nums[i] - nums[i - 1]);
            nums[i] += diff + 1;
            count += diff + 1;
        }
        return count;
    }
};