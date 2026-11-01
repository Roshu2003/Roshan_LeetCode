class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> one(n,0);
        one[n - 1] = (s[n - 1] == '1');
        for(int i = n - 2; i >= 0; i--)one[i] = one[i + 1] + (s[i] == '1');
        int zero = 0;
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            zero += (s[i] == '0');
            ans = max(ans,zero + one[i + 1]);
        }
        return ans;
    }
};