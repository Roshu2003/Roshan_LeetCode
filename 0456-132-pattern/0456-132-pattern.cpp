class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int mx = INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < mx)return true;
            while(!st.empty() && nums[i] > st.top()){
                mx = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
/*
Remember this pattern for interviews
Whenever you see:
\[
a < c < b
\]

with indices:
\[
i < j < k
\]

think about:
1. Traversing from right to left.
2. Maintaining a monotonic stack for possible b values.
3. Maintaining a variable for the best possible c.
4. Checking whether the current element can be a.
*/