class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> pref1(n,0),pref2(n,0);
        for(int i = 1; i < n; i++){
            int gap = nums[i] -  nums[i - 1];
            int c1 = 1;
            if(i > 1 && nums[i - 1] - nums[i - 2] <= gap){
                c1 = gap;
            } 
            int c2 = 1;
            if(i < n - 1 && gap > nums[i + 1] - nums[i]){
                c2 = gap;
            }
            pref1[i] = pref1[i - 1] + c1;
            pref2[i] = pref2[i - 1] + c2;
        }
        vector<int> ans;
        for(auto it : q){
            int l = it[0];
            int r = it[1];
            long long cost = 0;
            if(l < r){
                cost = pref1[r] - pref1[l];
            }
            else cost = pref2[l] - pref2[r];
            ans.push_back(cost);
        }
        return ans;
    }
};