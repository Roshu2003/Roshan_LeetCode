class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int st = 0;
        vector<long long> ans;
        for (int i = 0; i < nums.size(); i++) {
            long long curr = nums[i];
            while (!ans.empty() && ans.back() == curr) {
                curr += ans.back();
                ans.pop_back();
            }
            ans.push_back(curr);
        }
        return ans;
    }
};