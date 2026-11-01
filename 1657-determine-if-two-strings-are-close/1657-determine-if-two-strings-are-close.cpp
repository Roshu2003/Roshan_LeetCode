class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a(26,0),b(26,0);
        for(auto it : word1)a[it - 'a']++;
        for(auto it : word2)b[it - 'a']++;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        set<char> ast,bst;
        for(auto it : word1)ast.insert(it);
        for(auto it : word2)bst.insert(it);
        return a == b && ast == bst;
    }
};