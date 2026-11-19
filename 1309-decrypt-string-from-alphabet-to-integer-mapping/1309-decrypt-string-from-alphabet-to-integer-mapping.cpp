class Solution {
public:
    string freqAlphabets(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(i + 2 < s.size() && s[i + 2] == '#'){
                string t;
                t += s[i];
                t += s[i + 1];
                int x = stoi(t);
                ans += (x - 1 + 'a');
                i += 2;
            }
            else{
                int x = (s[i] - '0');
                ans += (x - 1 + 'a');
            }
        }
        return ans;
    }
};