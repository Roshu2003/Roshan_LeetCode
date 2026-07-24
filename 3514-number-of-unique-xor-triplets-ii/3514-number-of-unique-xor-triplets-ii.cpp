class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        // pre[0] = nums[0];
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] ^ nums[i];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                st.insert(nums[i] ^ nums[j]);
            }

    unordered_set<int> ans;
    for (auto i : st) {
        for (int j = 0; j < n; j++) {
            ans.insert(i ^ nums[j]);
        }
    }
    return (int)ans.size();
    }
}
;