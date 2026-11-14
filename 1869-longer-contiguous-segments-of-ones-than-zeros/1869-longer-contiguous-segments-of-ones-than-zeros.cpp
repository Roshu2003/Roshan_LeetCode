class Solution {
public:
    bool checkZeroOnes(string s) {
        // int ans = 0;
        int o = 0, z = 0;
        int one = 0;
        int zero = 0;
        s += '.';
        for (auto it : s) {
            if (it == '0') {
                o = max(o, one);
                one = 0;
                zero++;
            } else if(it == '1') {
                z = max(z, zero);
                one++;
                zero = 0;
            }
            if (it == '.') {
                o = max(o, one);
                z = max(z, zero);
            }
        }
        return o > z;
    }
};