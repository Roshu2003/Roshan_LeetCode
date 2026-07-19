class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        for(auto & it : nums){
            int x = 0;
            if(it < a)x = 0;
            else if(it > b)x = 2;
            else x = 1;
            it = x;
        }
        int zero = 0;
        int one = 0;
        int two = 0;
        int ans = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                ans =(ans + one + two) % mod;
                zero = (zero + 1) % mod;
            }
            else if(nums[i] == 1){
                one = (one + 1) % mod ;
                ans = (ans + two) % mod; 
            }
            else{
                two =( two + 1) % mod;
            }
        }
        return ans;
    }
};