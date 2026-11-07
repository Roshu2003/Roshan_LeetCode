class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> st;

        for(auto it : nums) {
            int k = it;

            for(int i = 2; i * i <= k; i++) {
                while(k % i == 0) {
                    st.insert(i);
                    k /= i;
                }
            }

            if(k > 1) {
                st.insert(k);
            }
        }

        return st.size();
    }
};