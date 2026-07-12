class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = 0; i < arr.size(); i++){
            pq.push({arr[i],i});
        }
        int n = arr.size();
        vector<int> ans(n,0);
        int rank = 1;
        int last = 0;
        // bool first = false;
        if(pq.size() > 0){
            ans[pq.top().second] = rank;
            last = pq.top().first;
            pq.pop();
        }
        while(!pq.empty()){
            auto it  = pq.top();
            pq.pop();
            if(last != it.first){
                rank++;
            }
            ans[it.second] = rank;
            last = it.first;
        }
        return ans;
    }
};