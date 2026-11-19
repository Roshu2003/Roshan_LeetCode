class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int mn = nums[i];
            int x = nums[i];
            for(int j = i; j < n; j++){
                mn = min(mn,nums[j]);
                x &= nums[j];
                if(x == mn){
                    ans++;
                }
            }
        }
        return ans;
    }
};