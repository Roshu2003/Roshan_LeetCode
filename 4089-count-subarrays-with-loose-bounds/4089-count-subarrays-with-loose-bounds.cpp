class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int st = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] >= minK && nums[i] <= maxK){
                ans += (i - st + 1);
            }
            else st = i + 1;
        }
        return ans;
    }
};