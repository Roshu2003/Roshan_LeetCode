class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int> mp;
        for(auto it : s)mp[it]++;
        map<char,int> mp1;
        for(auto it : target){
            mp1[it]++;
        }
        int ans = 1e9;
        for(auto it : mp1){
            ans = min(ans,mp[it.first] / it.second);
        }
        return ans;
    }
};