class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 2;
        int n = nums.size();
        int st = 0;
        int prod = 1;
        for(int i = 0; i < n; i++){
            while(gcd(prod,nums[i]) > 1){
                prod /= nums[st++];
            }
            prod *= nums[i];
            ans = max(ans,i - st + 1);
        }
        return ans;
    }
};