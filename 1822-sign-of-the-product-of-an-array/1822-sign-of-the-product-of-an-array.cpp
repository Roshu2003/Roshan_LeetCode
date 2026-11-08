class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long p = nums[0];
        int neg = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)return 0;
            else if(nums[i] < 0)neg++;
        }
        // if(p < 0)return -1;
        // if(p > 0)return 1
        if(neg % 2 == 1)return -1;
        return 1;
    }
};