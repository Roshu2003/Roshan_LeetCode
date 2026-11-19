
class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> st;

        // Find left boundaries
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (!st.empty() && (nums[st.back()] & x) == x) {
                st.pop_back();
            }

            if (!st.empty()) {
                left[i] = st.back();
            }

            st.push_back(i);
        }

        st.clear();
        long long ans = 0;
        // Find right boundaries
        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];

            while (!st.empty() && nums[st.back()] != x && (nums[st.back()] & x) == x) {
                st.pop_back();
            }
            int right = n;
            if (!st.empty()) {
                right = st.back();
            }
            ans += 1LL * (i - left[i]) * (right - i);
            st.push_back(i);
        }

        return ans;
    }
};
