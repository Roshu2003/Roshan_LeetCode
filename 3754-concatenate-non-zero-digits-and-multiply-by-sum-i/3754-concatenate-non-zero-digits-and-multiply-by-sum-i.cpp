class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        for(auto it : to_string(n)){
            if(it != '0'){
                num = num * 10 + (it - '0');
                sum += (it - '0');
            }
        }
        return num * 1LL * sum;
    }
};