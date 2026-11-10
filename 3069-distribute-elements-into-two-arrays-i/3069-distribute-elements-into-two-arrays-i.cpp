class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a, b;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if(i == 0)a.push_back(nums[i]);
            else if(i == 1)b.push_back(nums[i]);
            else{
                if(a.back() > b.back())a.push_back(nums[i]);
                else b.push_back(nums[i]);
            }
        }
        for (auto it : b)
            a.push_back(it);
        return a;
    }
};