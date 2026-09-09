class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000)return 0;
        // return n - 1000 + 1;
        long long ans = 0;
        for(long long i = 1000;  i <= n; i *= 1000){
            ans += n - i + 1;
        }
        return ans;
    }
};
//000 000 000 000 000 -> 4 
// 15 14 13 -> 4
// 12 11 10 -> 3
// 9 8 7 -> 2
// 6 5 4 -> 1