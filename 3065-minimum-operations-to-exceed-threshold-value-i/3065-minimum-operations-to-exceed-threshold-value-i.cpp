class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < k){
                return i + 1;
            }
        }
        return 0;
    }
};