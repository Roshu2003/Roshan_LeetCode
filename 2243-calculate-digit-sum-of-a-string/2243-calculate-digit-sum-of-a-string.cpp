class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k) {
            string t = "";
            int sum = 0;

            for(int i = 0; i < s.size(); i++) {
                sum += s[i] - '0';

                if((i + 1) % k == 0) {
                    t += to_string(sum);
                    sum = 0;
                }
            }

            if(s.size() % k != 0) {
                t += to_string(sum);
            }

            s = t;
        }

        return s;
    }
};