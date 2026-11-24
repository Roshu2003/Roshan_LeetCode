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
/*
Every subarray of length 2 is valid.
For length 3 or more, validity is equivalent to pairwise coprimality.
Use GCD with the window product to detect conflicts.
Shrink the window from the left until the conflict disappears.
*/