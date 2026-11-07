class Solution {
public:
    vector<int> assignTasks(vector<int>& server, vector<int>& task) {
        int m = server.size();
        int n = task.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> busy,idle;
        for(int i = 0; i < m ; i++){
            idle.push({server[i],i});
        }
        long long ts = 0;
        auto release = [&](){
            while(!busy.empty() && busy.top().first <= ts){
                idle.push({server[busy.top().second],busy.top().second});
                busy.pop();
            }
        };

        vector<int> ans;
        for(long long i = 0; i < n; i++){
            ts = max(ts,i);
            release();
            if(idle.empty()){
                ts = busy.top().first;
                release();
            }
            auto [_,idx] = idle.top();
            ans.push_back(idx);
            busy.push({ts + task[i],idx});
            idle.pop();
        }
        return ans;
    }
};