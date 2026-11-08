class Solution {
public:
    bool squareIsWhite(string s) {
        int n = (s[1] - '0') + (s[0] - 'a');
        if(n % 2 == 1)return false;
        return true;
    }
};