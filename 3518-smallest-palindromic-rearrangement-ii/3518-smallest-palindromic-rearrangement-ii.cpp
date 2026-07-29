class Solution {
public:
    int maxN = 1e6 + 1;
    long long find(vector<int>& a, int tot) {
        long long res = 1;
        auto get = [&](int n, int r) -> long long {
            if (r > n)
                return 0;
            long long ans = 1;
            for (int i = 1; i <= r; i++) {
                ans = ans * (n - r + i) / i;
                if (ans > maxN)
                    return maxN;
            }
            return ans;
        };
        for (int i = 0; i < 26; i++) {
            if (a[i]) {
                res *= get(tot, a[i]);
                if (res > maxN)
                    return maxN;
                tot -= a[i];
            }
        }
        return res;
    }
    string smallestPalindrome(string s, int k) {
        vector<int> feq(26, 0);
        vector<int> half(26, 0);
        int tot = 0;
        string mid = "";
        for (auto it : s)
            feq[it - 'a']++;
        for (int i = 0; i < 26; i++) {
            half[i] = feq[i] / 2;
            tot += half[i];
            if ((feq[i] & 1))
                mid = 'a' + i;
        }

        vector<int> a(26);
        for (int i = 0; i < 26; ++i) {
            a[i] = half[i];
        }
        if (k > find(a, tot))
            return "";

        string first = "";
        while (tot--) {
            for (int i = 0; i < 26; i++) {
                if (a[i]) {
                    --a[i];
                    long long cnt = find(a, tot);
                    if (cnt >= (long long)k) {
                        first += 'a' + i;
                        break;
                    }
                    k -= cnt;
                    ++a[i];
                }
            }
        }
        string second = first;
        reverse(second.begin(), second.end());
        string temp = first + mid + second;
        string ans;
        for (auto it : temp) {
            if (it != ' ') {
                ans += it;
            }
        }
        return ans;
    }
};