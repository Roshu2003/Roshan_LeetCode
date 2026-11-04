class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int> mp;
        for(auto it : words){
            for(auto  i : it)mp[i]++;
        }
        int n = words.size();
        // if(n == 1)return true;
        for(auto [it,cnt] : mp){
            if(cnt % n != 0)return false;
        }
        return true;
    }
};