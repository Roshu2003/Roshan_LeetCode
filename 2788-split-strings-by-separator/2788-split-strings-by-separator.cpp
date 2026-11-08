class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char sp) {
        vector<string> ans;
        for(auto &it : words){
            string s = "";
            it += sp;
            for(auto i : it){
                if(i == sp){
                    if(!s.empty()){
                        ans.push_back(s);
                    }
                    s = "";
                }else s += i;
            }
        }
        return ans;
    }
};