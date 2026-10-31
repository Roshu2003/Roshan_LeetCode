class Solution {
public:
    int countElements(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        int ans =0 ;
        for(auto it : nums){
            if(mn < it && it < mx)ans++;
        }
        return ans;
    }
};