class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid = n / 2;
        long long temp = nums[mid];
        for(auto x : nums){
            ans += abs(x - temp);
        }
        return ans;
    }
};
/*
    sum = 22
    1 -> 4 -> (21 - 4) = 17
    10 -> 40 -> (12 - 40) = 28
    2 -> 8 -> (20 - 8) = 12

*/