class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        int n = prices.size();
        vector<int> ns(n,0);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && prices[st.top()] > prices[i]){
                st.pop();
            }
            if(!st.empty())ns[i] = prices[st.top()];
            st.push(i);
        }
        for(auto i = 0 ; i < n; i++){
            int discount = prices[i] - ns[i];
            ans.push_back(discount);
        }
        return ans;
    }
};