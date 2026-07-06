class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        int cnt = 0;
        sort(nums.begin(),end(nums),[](auto &a , auto &b){
            if(a[0] == b[0])return a[1] > b[1];
            return a[0] < b[0];
        });
        int mx = 0;
        for(auto it : nums){
            if(it[1] > mx){
                mx = it[1];
                cnt++;
            }
        }
        return cnt;
    }
};