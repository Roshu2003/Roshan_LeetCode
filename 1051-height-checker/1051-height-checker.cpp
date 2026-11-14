class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> nums = heights;
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != heights[i])ans++;
        }
        return ans;
    }
};