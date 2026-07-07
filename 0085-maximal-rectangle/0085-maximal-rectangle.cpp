class Solution {
public:
    vector<int> L(vector<int> & nums){
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = 0; i <n ;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> R(vector<int> & nums){
        int n = nums.size();
        vector<int> ans(n,n);
        stack<int> st;
        for(int i = n - 1;  i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int find(vector<int> &nums){
        int n = nums.size();
        vector<int> l = L(nums);
        vector<int> r = R(nums);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int x = r[i] - l[i] - 1;
            ans = max(ans,nums[i] * x);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> h(m,0);
        for(int i = 0; i <n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '0'){
                    h[j] = 0;
                }
                else{
                    h[j]++;
                }
            }
            ans = max(ans,find(h));
        }
        return ans;
    }
};