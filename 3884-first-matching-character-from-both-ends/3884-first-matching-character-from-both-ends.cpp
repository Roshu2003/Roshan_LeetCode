class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.size();
        for(int i = 0; i < s.size(); i++){
            if(s[i] == s[n - 1 - i])return i;
        }
        return -1;
    }
};