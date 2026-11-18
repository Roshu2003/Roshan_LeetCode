class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i = 1; i < n; i += 2){
            if(s[i] != s[i - 1]){
                cnt++;
            }
        }
        // int x = n / 2 - cnt;
        // if(cnt >= 2)return 0;
        // if(cnt == 1)return 1;
        // return 2;
        return cnt;
    }
};