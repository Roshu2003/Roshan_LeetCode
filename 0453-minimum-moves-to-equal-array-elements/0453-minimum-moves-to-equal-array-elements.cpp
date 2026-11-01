class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *min_element(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);
        return sum - mx * nums.size();
    }
};