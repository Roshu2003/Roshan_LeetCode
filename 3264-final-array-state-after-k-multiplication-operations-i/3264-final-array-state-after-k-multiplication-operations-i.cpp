class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        vector<int> ans(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(int i = 0; i < n; i++)pq.push({nums[i],i});
        while(k--){
            auto it = pq.top();
            pq.pop();
            pq.push({it.first * mul,it.second});
        }
        while(!pq.empty()){
            auto [num,i] = pq.top();
            pq.pop();
            ans[i] = num;
        }
        return ans;
    }
};