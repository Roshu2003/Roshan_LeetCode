class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char,int> mp;
        for(int i = 0; i < chars.size(); i++){
            mp[chars[i]] = vals[i];
        }
        int ans =0 ;
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                sum += mp[s[i]];
            }
            else sum += (s[i] - 'a' + 1);
            if(sum < 0){
                sum = 0;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};