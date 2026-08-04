class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        set<int> st(nums.begin(),nums.end());
        int i = *st.begin();
        int n = *st.rbegin();
        for(;i <= n; i++){
            if(st.count(i))continue;
            ans.push_back(i);
        }
        return ans;
    }
};