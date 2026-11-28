class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            long long x = 1LL * mid * mid;
            if(x == num)return true;
            else if(x > num){
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return false;
    }
};