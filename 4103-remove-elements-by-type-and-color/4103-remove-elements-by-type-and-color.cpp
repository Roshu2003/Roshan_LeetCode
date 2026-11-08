class Solution {
public:
    bool canRemoveAll(vector<int>& ty, vector<int>& col, vector<int>& g) {
        stack<tuple<int,int,int>> st;

        for(int i = 0; i < ty.size(); i++) {

            if(!st.empty() &&
               get<0>(st.top()) == ty[i] &&
               get<1>(st.top()) == col[i]) {

                get<2>(st.top())++;
            }
            else {
                st.push({ty[i], col[i], 1});
            }

            auto [t, c, cnt] = st.top();

            if(cnt % g[t] == 0) {
                st.pop();
            }
        }

        return st.empty();
    }
};