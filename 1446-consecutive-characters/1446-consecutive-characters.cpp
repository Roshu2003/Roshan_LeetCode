class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        int cnt = 1;
        s += '@';
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i - 1]){
                ans = max(ans,cnt);
                cnt = 1;
            }else cnt++;
        }
        return ans;
    }
};