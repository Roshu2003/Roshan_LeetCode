class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> cnt(26,0);
        for(auto it : s)cnt[it - 'a']++;
        int ans = 0;
        for(auto it : cnt)ans += (it != 0);
        return ans;
    }
};