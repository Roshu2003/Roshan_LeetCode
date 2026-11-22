class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto it : words){
            map<char,char> mp1,mp2;
            bool ok = true;
            for(int i = 0; i < it.size(); i++){
                char a = pattern[i];
                char b = it[i];

                if(mp1.count(a) && mp1[a] != b){
                    ok = false;
                    break;
                }
                if(mp2.count(b) && mp2[b] != a){
                    ok = false;
                    break;
                }
                mp1[a] = b;
                mp2[b] = a;
            }
            if(ok)ans.push_back(it);
        }
        return ans;
    }
};