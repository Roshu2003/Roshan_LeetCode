class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<int,int> mp;
        for(auto it : s)mp[it]++;
        int f = -1;
        for(auto [it,cnt] : mp){
            if(f == -1){
                f = cnt;
            }
            else {
                if(f != cnt)return false;
            }
        }
        return true;
    }
};