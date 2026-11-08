class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int ans = -1;
        vector<int> cnt(26,-1);
        for(int i= 0 ; i < n; i++){
            int idx = s[i] - 'a';
            if(cnt[idx] == -1){
                cnt[idx] = i;
            }
            else{
                ans = max(ans,i - cnt[idx] - 1);
            }
        }
        return ans;
    }
};