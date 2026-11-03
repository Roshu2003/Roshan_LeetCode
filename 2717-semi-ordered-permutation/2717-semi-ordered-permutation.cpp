class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1)first = i;
            if(nums[i] == n)last = i;
        }
        if(first > last)return n - last - 1 + first - 1;
        return n - last - 1 + first;
    }
};