class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int st = 0;
        int curr = nums[0];
        vector<long long>ans;
        for(int i = 0; i < nums.size(); i++){
            if(ans.empty()){
                ans.push_back(nums[i]);
            }
            else{
                long long curr = nums[i];
                while(!ans.empty() && ans.back() == curr){
                    curr += ans.back();
                    ans.pop_back();
                }
                ans.push_back(curr);
            }
        }
        return ans;
    }
};