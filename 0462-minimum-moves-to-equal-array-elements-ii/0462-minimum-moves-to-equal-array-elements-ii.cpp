class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long ans = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            long long sum = 0;
            for(int j = 0; j < n; j++){
                sum += abs(nums[i] - nums[j]);
            }
            ans = min(ans,sum);
        }
        return ans;
    }
};