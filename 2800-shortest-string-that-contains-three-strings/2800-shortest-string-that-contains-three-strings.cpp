class Solution {
public:
    string merge(string a, string b) {
        int n = a.size();
        int m = b.size();
        if (a.find(b) != string::npos)
            return a;

        if (b.find(a) != string::npos)
            return b;
        int overlap = 0;
        for (int i = 1; i <= min(n, m); i++) {
            if (a.substr(n - i) == b.substr(0, i))
                overlap = i;
        }
        return a + b.substr(overlap);
    }
    string minimumString(string a, string b, string c) {
        string ans;
        vector<string> v = {a, b, c};
        sort(v.begin(), v.end());
        do {
            string s = merge(v[0], v[1]);
            s = merge(s, v[2]);
            if (ans.empty() || s.size() < ans.size() || (s.size() == ans.size() && s < ans)) {
                ans = s;
            }
        } while (next_permutation(v.begin(), v.end()));
        return ans;
    }
};