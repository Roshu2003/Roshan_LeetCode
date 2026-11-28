class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int ans = 0;
        int mx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mx = max(mx,nums[i]);
            if(i == mx)ans++;
        }
        return ans;
    }
};