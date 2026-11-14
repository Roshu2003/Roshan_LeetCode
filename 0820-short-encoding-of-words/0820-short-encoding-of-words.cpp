class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> st(words.begin(),words.end());
        for(auto it : words){
            for(int k  = 1; k < it.size(); k++){
                st.erase(it.substr(k));
            }
        }
        int ans = 0;
        for(auto it : st)ans += it.size() + 1;
        return ans;
    }
};