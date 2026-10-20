class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int cnt = 0;
        int ans = 0;
        int i = 0;
        for(auto it : s){
            if(it == '('){
                // st.push(it);
                cnt++;
            }
            else{
                cnt--;
                if(s[i - 1] == '(') ans += (1 << cnt);
            }
            i++;
        }
        return ans;
    }
};