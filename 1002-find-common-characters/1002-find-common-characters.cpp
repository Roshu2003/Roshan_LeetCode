class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> cnt(26,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            for(auto it : words[i]){
                cnt[it - 'a'][i]++;
            }
        }
        vector<string> ans;
        for(int i = 0; i < 26; i++){
            string s = "";
            s += (i + 'a');
            int mx = INT_MAX;
            for(auto it : cnt[i]){
                mx = min(mx,it);
            }
            while(mx--)ans.push_back(s);
        }
        return ans;
    }
};