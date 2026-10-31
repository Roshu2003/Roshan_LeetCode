class Solution {
public:
    string addStrings(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int carry = 0;
        string ans = "";
        while(i >= 0 && j >= 0){
            int sum = (s[i] - '0') + (t[j] - '0') + carry;
            ans += (sum % 10 + '0');
            carry = sum / 10;
            i--;
            j--;
        }
        while(i >= 0){
            int sum = (s[i] - '0') + carry;
            ans += (sum % 10 + '0');
            carry = sum / 10;
            i--;
        }
         while(j >= 0){
            int sum = (t[j] - '0') + carry;
            ans += (sum % 10 + '0');
            carry = sum / 10;
            j--;
        }
        if(carry > 0){
            ans += (carry + '0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};