class Solution {
public:
    bool check(string s,int f){
        string t = s;
        sort(s.begin(),end(s));
        int n = s.size();
        if(f == 1){
            sort(t.begin(),t.end() - 1);
            return s == t;
        }
        else{
            sort(t.begin() + 1,t.end());
            return s == t;
        }
        return true;
    }
    bool check1(string t,int f){
        string s = t;
        sort(s.begin(),s.end());
        if(f == 1){
            sort(t.begin(),t.end() - 1);
            sort(t.begin() + 1,t.end());
            return t == s;
        }
        sort(t.begin() + 1,t.end());
        sort(t.begin(),t.end() - 1);
        return t == s;
    }
    int minOperations(string s) {
        int n = s.size();
        string t = s;
        sort(t.begin(),t.end());
        if(n == 1)return 0;
        if(n == 2){
            if(s == t)return 0;
            return -1;
        }
        if(s == t)return 0;
        if(check(s,1) || check(s,0))return 1;

        if(check1(s,1) || check1(s,0))return 2;
        return 3;
    }
};