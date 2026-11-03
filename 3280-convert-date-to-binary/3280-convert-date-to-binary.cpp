class Solution {
public:
    string find(int n){
        string s = "";
        while(n > 0){
            int x = (n % 2);
            s += (x + '0');
            n /= 2;
        }
        reverse(s.begin(),s.end());
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