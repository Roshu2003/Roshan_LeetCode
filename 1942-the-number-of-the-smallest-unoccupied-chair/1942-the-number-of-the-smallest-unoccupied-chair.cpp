class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,int>> v;
        for(int i = 0; i < times.size(); i++){
            v.push_back({times[i][0],i});
        }
        sort(v.begin(),v.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        set<int> st;
        for(int i = 0; i < v.size(); i++)st.insert(i);
        int time = 0;
        for(int i = 0; i < v.size(); i++){
            int start = v[i].first;
            int fd = v[i].second;
            int end = times[fd][1];
            while(!pq.empty() && pq.top().first <= start){
                st.insert(pq.top().second);
                pq.pop();
            }
            if(fd == targetFriend)return *st.begin();
            pq.push({end,*st.begin()});
            st.erase(st.begin());

        }
        return -1;
    }
};