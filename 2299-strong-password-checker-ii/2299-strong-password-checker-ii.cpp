class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        int n = s.size();
        if(n < 8)return false;
        int ok = 0;
        string t = "!@#$%^&*()-+";
        for(auto i = 0; i < n; i++){
            char it = s[i];
            if(it >= 'A' && it <= 'Z'){
                ok |= 1;
            }
            if(it >= 'a' && it <= 'z') ok |= (1 << 1);
            if(it >= '0' && it <= '9') ok |= (1 << 2);
            if(t.find(it) != -1)ok |= (1 << 3);
            if(i - 1 >= 0 && s[i] == s[i - 1])return false;
        }
        // cout<<ok<<endl;
        return ok == ((1 << 4) - 1);
    }
};