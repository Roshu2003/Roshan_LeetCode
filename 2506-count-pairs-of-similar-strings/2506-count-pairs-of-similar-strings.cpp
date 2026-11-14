class Solution {
public:
    void count(string s,set<char> & st){
        for(auto it : s)st.insert(it);
    }
    int similarPairs(vector<string>& s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            set<char> si;
            count(s[i],si);
            for(int j = i + 1; j < n; j++){
                set<char> sj;
                count(s[j],sj);
                if(sj == si)ans++;
            }
        }
        return ans;
    }
};