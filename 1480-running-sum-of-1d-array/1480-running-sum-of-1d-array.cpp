class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(auto it : nums){
            if(ans.empty()){
                ans.push_back(it);
            }
            else{
                ans.push_back(ans.back() + it);
            }
        }
        return ans;
    }
};