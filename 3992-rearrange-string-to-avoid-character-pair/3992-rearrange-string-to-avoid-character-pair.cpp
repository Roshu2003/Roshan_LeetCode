class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int cx  = 0;
        int cy  = 0;
        string t,sx,sy;
        for(auto it : s){
            if(it == x){
                sx += it;
            }
            else if(it == y){
                sy += it;
            }
            else t += it;
        }
        t = sy + t + sx;
        return t;
    }
};