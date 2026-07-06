class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans = 0;
        long long cnt = 0;
        map<int,long long> mp;
        int leftcnt = 0;
        int n = nums.size();
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                // cnt++;
                leftcnt += mp[cnt];
                cnt++;
            }else{
                cnt--;
                leftcnt -= mp[cnt];
                // cnt--;
            }
            mp[cnt]++;
            ans += leftcnt;
        }
        return ans;
    }
};
// 1 2 2 3
//-1 
//
//