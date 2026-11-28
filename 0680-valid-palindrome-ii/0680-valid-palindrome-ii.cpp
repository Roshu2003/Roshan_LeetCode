class Solution {
public:
    bool check(int i,int j,string s){
        while(i <= j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0;
        int j = n - 1;
        while(i <= j){
            if(s[i] != s[j]){
                if(check(i + 1,j,s) || check(i,j - 1,s))return true;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};