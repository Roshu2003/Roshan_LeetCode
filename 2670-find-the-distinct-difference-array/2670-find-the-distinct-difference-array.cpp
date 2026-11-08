class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n =  nums.size();
        vector<int> suff(n + 1,0),pre(n,1);
        set<int> st;
        for(int i = n - 1;i >= 0; i--){
            st.insert(nums[i]);
            suff[i] = st.size();
        }
        st.clear();
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
            ans[i] = -suff[i + 1] + st.size();
        }
        return ans;
    }
};