class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        // int sum = 0;
        // int st = 0;
        int ans = INT_MAX;
        int n = nums.size();
        //Brute force
        // for(int i = 0; i < n; i++){
        //     int sum = 0;
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];
        //         if((j - i + 1) >= l && (j - i + 1) <= r && sum > 0)ans = min(ans,sum); 
        //     }
        // }

        //Optimal solution
        multiset<int> st;
        vector<int> pre(n + 1,0);// one based index prefix sum
        partial_sum(nums.begin(),nums.end(),pre.begin() + 1);
        for(int j = l ; j <= n; j++){
            st.insert(pre[j - l]);
            if(j > r){//invalide subarray
                st.erase(st.find(pre[j - r - 1]));                
            }
            auto it = st.lower_bound(pre[j]);
            if(it != st.begin()){
                ans = min(ans,pre[j] - *prev(it));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};