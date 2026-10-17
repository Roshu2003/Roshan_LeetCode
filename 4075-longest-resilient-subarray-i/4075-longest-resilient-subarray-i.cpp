class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int ans = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] = (nums[i] % k);
        }
        int l = 0;
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1]){
                l = i;
                cnt = 1;
            }
            else{
                cnt++;
                if(((i - l) * nums[i - 1]) % k == 0)
                    ans = max(ans,cnt);
            }
        }
        if(((n - l - 1) * nums[n - 1]) % k == 0)
            ans = max(ans,cnt);
        return ans;
    }
};
/*
i..j = sum;
9 9 9 9 9 9 6 0
*/