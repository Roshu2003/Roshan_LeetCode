class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<int,int> mp;
        int ans = 0;
        int st = 0;
        for(auto i = 0; i< s.size(); i++){
            mp[s[i]]++;
            while(mp[s[i]] > 2){
                mp[s[st]]--;
                st++;
            }
            ans = max(ans,i - st + 1);
        }
        return ans;
    }
};