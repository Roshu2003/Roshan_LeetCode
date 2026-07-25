class Solution {
public:
    int maxProduct(int n) {
        int mx = -1;
        int smx = -1;
        while(n > 0){
            int x = n % 10;
            if(x >= mx){
                smx = mx;
                mx = x;
            }
            else{
                smx = max(smx , x);
            }
            n /= 10;
        }
        return mx * smx;
    }
};