class Solution {
public:
    int hIndex(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        int ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] >= n - mid){
                ans = n - mid;
                r =  mid - 1;
            }else l = mid + 1;
        }
        return ans;
    }
};