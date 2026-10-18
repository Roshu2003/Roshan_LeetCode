class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt = 1;
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1]){
                ans += cnt - 1;
                cnt = 1;
            }
            else cnt++;
        }
        ans += cnt - 1;
        return ans;
    }
};