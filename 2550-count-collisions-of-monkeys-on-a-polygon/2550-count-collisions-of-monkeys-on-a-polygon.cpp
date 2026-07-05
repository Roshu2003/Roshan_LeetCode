class Solution {
public:
    int monkeyMove(int n) {
        long long ans = 1;
        long long b = 2;
        int mod = 1e9 + 7;
        while(n){
            if(n%2){
                ans = ans * b % mod;
            }
            b = b * b % mod;
            n >>= 1;
        }
        return (ans - 2 + mod) % mod;
    }
};