class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int maxP = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)continue;
                if(nums[i] + nums[j] == target && nums[i] > nums[j]){
                    if(nums[i] * nums[j] > maxP){
                        maxP = nums[i] * nums[j];
                        ans = {i,j};
                    }
                }
            }
        }
        return  ans;
    }
};