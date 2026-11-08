class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int n = s.size();
        int a = -1,b = -1,c = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a')a = i;
            else if(s[i] == 'b')b = a;
            else c = b;
            ans += i - c;
        }
        return ans;
    }
};