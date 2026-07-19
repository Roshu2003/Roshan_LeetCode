class Solution {
public:
    string smallestSubsequence(string s) {
        map<char,int> mp;
        for(auto it : s)mp[it]++;
        set<char> vis;
        stack<char> st;
        for(auto c : s){
            mp[c]--;
            if(vis.count(c))continue;
            while(!st.empty() && st.top() > c && mp[st.top()] > 0){//remove the bigger char if they apperaes leter
                vis.erase(st.top());
                st.pop();
            }
            vis.insert(c);
            st.push(c);
        }
        string ans = "";
        while(!st.empty()){
            ans = string(1,st.top()) + ans;
            st.pop();
        }
        return ans;
    }
};