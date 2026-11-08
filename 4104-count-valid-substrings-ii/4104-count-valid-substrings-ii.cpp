class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();

        long long total = 1LL * n * (n + 1) / 2;
        long long invalid = 0;

        int a = -1, ab = -1, abc = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') {
                a = i;
            }
            else if (s[i] == 'b') {
                if (a != -1) {
                    ab = a;
                }
            }
            else if (s[i] == 'c') {
                if (ab != -1) {
                    abc = ab;
                }
            }

            if (abc != -1) {
                invalid += abc + 1;
            }
        }

        return total - invalid;
    }
};