class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int idx = max_element(nums.begin(),end(nums)) - nums.begin();
        int n = nums.size();
        int rs = n - 1 - idx;
        int i = (idx + 1) % n;
        while(i != idx){
            if(nums[i] > nums[(i + 1) % n])return -1;
            i = (i + 1) % n;
        }
        return rs;
        return idx;
    }
};