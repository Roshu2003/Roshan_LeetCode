class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& qr) {
        sort(logs.begin(),logs.end(),[](auto a,auto b){
            return a[1] < b[1];
        });
        vector<pair<int,int>> p;
        for(int i = 0; i <qr.size(); i++){
            p.push_back({qr[i],i});
        }
        int m = qr.size();
        sort(p.begin(),p.end());
        vector<int> ans(m,0);
        unordered_map<int,int> mp;
        int i = 0;
        int j = 0;
        for(auto [it,idx] : p){
            int st = it - x;
            int ed = it;
            while(j < logs.size() && logs[j][1] <= ed){
                mp[logs[j][0]]++;
                j++;
            }
            while(i < j && logs[i][1] < st){
                if(--mp[logs[i][0]] == 0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }
            ans[idx] = n - mp.size();
        }
        return ans;
    }
};