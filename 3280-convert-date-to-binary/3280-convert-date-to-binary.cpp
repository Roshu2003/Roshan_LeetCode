class Solution {
public:
    string find(int n){
        string s = "";
        while(n > 0){
            int x = (n % 2);
            s = to_string(x) + s;
            n /= 2;
        }
        return s;
    }
    string convertDateToBinary(string s) {
        string ans = "";
        string t = "";
        s += '-';
        for(auto it : s){
            if(it == '-'){
                int n = stoi(t);
                ans += find(n);
                ans += '-';
                t = "";
            }else t += it;
        }
        ans.pop_back();
        return ans;
    }
};