class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int k = n / 2;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        set<int>st;
        for(auto it : s1){
            if(s2.count(it))st.insert(it);
        }
        int u1 = s1.size() - st.size();
        int u2 = s2.size() - st.size();

        int take1 = min(u1,k);
        int take2 = min(u2,k);

        int rem = n - take1 - take2;

        return take1 + take2 + min(rem,(int)st.size());
    }
};