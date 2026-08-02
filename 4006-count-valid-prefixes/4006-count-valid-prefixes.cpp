class Solution {
public:
    int countValidPrefixes(string s) {
        int ans = 0;
        int cnt = 0;
        for(auto it : s){
            cnt += (it - '0' == 1) ? 1 : -1;
            cout<<cnt<<endl;
            if(abs(cnt) == 1 || cnt == 0)ans++;
        }
        return ans;
    }
};