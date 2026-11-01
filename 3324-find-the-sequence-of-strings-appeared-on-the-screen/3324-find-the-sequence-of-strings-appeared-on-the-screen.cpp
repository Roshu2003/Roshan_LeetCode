class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string s = "";
        for(auto it : target){
            s += 'a';
            ans.push_back(s);
            while(s.back() != it){
                s.back()++;
                ans.push_back(s);
            }
        }
        return ans;
    }
};