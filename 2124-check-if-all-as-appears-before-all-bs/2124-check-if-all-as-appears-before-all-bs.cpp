class Solution {
public:
    bool checkString(string s) {
        int i = 0;
        int n = s.size();
        while(i < n && s[i] == 'a')i++;
        // if(i == 0 || i == n)return false;
        while(i < n){
            if(s[i] == 'a')return false;
            i++;
        }
        return true;
    }
};