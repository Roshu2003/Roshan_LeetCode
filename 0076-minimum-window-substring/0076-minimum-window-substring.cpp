class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        map<char,int> mp;
        int st = 0;
        int cnt = 0;//track the match count of s to t;
        int len = INT_MAX;
        int start = 0;
        for(auto it : t)mp[it]++;
        for(int i = 0; i < n ; i++){
            if(mp[s[i]] > 0)cnt++;
            mp[s[i]]--;//we can't use again

            while(cnt == m){
                if(i - st + 1 < len){
                    len = i - st + 1;
                    start = st;
                }
                mp[s[st]]++;
                if(mp[s[st]] > 0)cnt--;
                st++;
            }
        }
        return len == INT_MAX ? "":s.substr(start,len);
    }
};