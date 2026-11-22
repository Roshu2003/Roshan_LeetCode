class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < k; i++) {
            if (nums[i] < 0)
                mp[nums[i]]++;
        }
        int st = 0;
        for (int i = k; ; i++) {
            int y = 0;
            int xx = x;
            for (auto [a, b] : mp) {
                if (xx > b) {
                    xx -= b;
                } else {
                    y = a;
                    break;
                }
            }
            ans.push_back(y);
            if (i == n) break;
            if (nums[i] < 0)
                mp[nums[i]]++;
            if (nums[st] < 0) {
                if (--mp[nums[st]] == 0)
                    mp.erase(nums[st]);
            }
            st++;
        }
        return ans;
    }
};