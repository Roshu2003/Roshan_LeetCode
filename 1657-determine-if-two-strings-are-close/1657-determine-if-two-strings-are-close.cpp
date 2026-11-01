class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a(26,0),b(26,0);
        for(auto it : word1)a[it - 'a']++;
        for(auto it : word2)b[it - 'a']++;
        for(int i = 0; i < 26; i++){
            if((a[i] == 0 && b[i] != 0) || (b[i] == 0 && a[i] != 0))return false;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a == b;
    }
};