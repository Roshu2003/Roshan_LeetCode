class Solution {
public:
    long long maximumValue(int n, int a, int d) {
        // d = m;
        // a = s;
        // n = n;
        //an = a + (n - 1) * d;
        // return s + (n - 1) * 1LL *
        if(n == 1)return a;
        long long ans =  a + (n / 2) * 1LL * d - (n - 1) / 2;// last element
        long long ans1 = ans;
        if(n % 2 == 0){
            ans1 -= d;
        }else ans1 += 1;
        return max(ans,ans1); 
    }
};// 3 7 7
// a  a + m  (a + m - 1)  ((a + m - 1) + m)  ((a + m - 1) + m - 1)  ((a + m - 1) + m - 1 + m)
//a + (n / 2) * m - ((n - 1) / 2);
//3 + 2 * 5 - (3 / 2) = 13 - 1 = 12
//1 2 3