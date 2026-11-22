class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                ans += (nums[i] >= nums[i + 1]);
            }else if(i == n - 1){
                ans += (nums[i] >= nums[i - 1]);
            }
            else{
                if((nums[i - 1] + nums[i + 1]) <= nums[i] * 2)ans++;
            }
        }
        return ans;
    }
};