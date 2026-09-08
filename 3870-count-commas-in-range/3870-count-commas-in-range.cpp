class Solution {
public:
    int countCommas(int n) {
       int ans = 0;
       for(int i = 1000; i<= n; i++){
        string s = to_string(i);
        int cnt  = (s.size()) / 3;
        int len = s.size();
        if(len % 3 == 0)cnt--;
        ans += cnt;
       } 
       return ans;
    }
};
// 2222222