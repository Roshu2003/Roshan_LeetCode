class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        for(string& w : words){
            reverse(w.begin(),w.end());
        }
        sort(words.begin(),words.end(),[](const string& a, const string& b){
            return a < b;
        });
        int res = 0;
        for(int i = 0;i<n;i++){
            if(i+1<n && words[i+1].substr(0,words[i].size()) == words[i]){
                continue;
            }else{
                res += words[i].size() + 1;
            }
        }
        return res;
    }
};