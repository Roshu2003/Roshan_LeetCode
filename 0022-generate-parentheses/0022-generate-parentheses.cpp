class Solution {
public:
    vector<string> ans;
    int n;
    void solve(int o,int c,string s){
        if(2 * n == s.size()){
            ans.push_back(s);
            return;
        }
        if(o < n){
            s += '(';
            solve(o + 1,c,s);
            s.pop_back();
        }
        if(c < o){
            s += ')';
            solve(o,c + 1,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int _n) {
        int o =0 ,c = 0;
        string s = "";
        // n = 2 * _n;
        n = _n;
        solve(o,c,s);
        return ans;
    }
};