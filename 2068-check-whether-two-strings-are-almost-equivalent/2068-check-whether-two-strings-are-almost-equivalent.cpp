class Solution {
public:
    bool checkAlmostEquivalent(string s, string t) {
        vector<int> a(26,0),b(26,0);
        for(auto it : s)a[it - 'a']++;
        for(auto it : t)b[it - 'a']++;
        for(int i = 0; i < 26; i++){
            if(abs(a[i] - b[i]) > 3)return false;
        }
        return true;
    }
};