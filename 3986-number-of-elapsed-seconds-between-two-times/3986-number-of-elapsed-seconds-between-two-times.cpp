class Solution {
public:
    int find(string &s){
        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        int sec = (s[6] - '0') * 10 + (s[7] - '0');
        return h * 60 * 60 + m * 60 + sec;
    }
    int secondsBetweenTimes(string st, string ed) {
        int a = find(st);
        int b = find(ed);
        return b - a;
    }
};