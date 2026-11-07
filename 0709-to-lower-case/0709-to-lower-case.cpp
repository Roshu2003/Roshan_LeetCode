class Solution {
public:
    string toLowerCase(string s) {
        for(auto &it : s){
            if(it >= 'A' && it <= 'Z'){
                it = char(it - 65 + 97);
            }
        }
        return s;
    }
};
/*
    A - 65
    a - 97 
*/