class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        // int mn = nums.back();
        vector<int> rightMin(n);
        rightMin.back() = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)rightMin[i] = min(rightMin[i + 1],nums[i]);
        int ans = 0;
        int mx = 0;
        for(int i = 0; i < n - 1; i++){
            mx = max(mx,nums[i]);
            if(mx <= rightMin[i + 1]){
                ans = max(ans,i + 1);
                break;
            }
        }
        return ans;
    }
};