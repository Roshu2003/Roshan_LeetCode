class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int n = s.size();
        int curr = 0;
        for(int i = 0; i < n; i++){
            int tar = s[i] - '0';
            int d = (tar - curr + 10) % 10;
            ans += min(d,10 - d);
            curr = tar;
        }
        return ans;
    }
};
// 3 1 1 - 3 = 2 % 9 = 7  3 4 5 6 7 8 9 0 1
// 2 9       9 0 1 2 (2 - 0) + (10 - tar)
// 9  2   9 0 1 2 -> 2
//   2 3 4 5 6 7 8 9