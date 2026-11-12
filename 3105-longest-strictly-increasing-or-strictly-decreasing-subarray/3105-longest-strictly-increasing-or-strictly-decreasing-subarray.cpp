class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int a = 1;
        int b = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                ans = max(ans,b);
                b = 1;
                a++;
            }
            else if(nums[i] < nums[i - 1]){
                ans = max(ans,a);
                a = 1;
                b++;
            }
            else{
                ans = max(ans,b);
                b = 1;
                ans = max(ans,a);
                a = 1;
            }
        }
        ans = max(ans,a);
        ans = max(ans,b);
        return ans;
    }
};