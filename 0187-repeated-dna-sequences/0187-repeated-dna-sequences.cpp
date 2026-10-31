class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        string t = "";
        int k = 10;
        int n = s.size();
        for(int i = 10 ; i <= n; i++){
            t = s.substr(i - k,10);
            mp[t]++;
        }
        vector<string> ans;
        for(auto it : mp){
            if(it.second > 1)ans.push_back(it.first);
        }
        return ans;
    }
};