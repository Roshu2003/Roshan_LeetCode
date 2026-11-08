class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(auto s : emails){
            string t = "";
            bool ok = true;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '.'){
                    continue;
                }
                else if(s[i] == '+'){
                    while(i < s.size() && s[i] != '@')i++;
                    i--;
                }
                else if(s[i] == '@'){
                    t = t + s.substr(i);
                    // cout<<t<<endl;
                    break;
                }else t += s[i];
            }
            // cout<<t<<endl;
            st.insert(t);
        }
        return st.size();
    }
};