class Solution {
public:
    bool validDigit(int n, int x) {
        bool ok = false;
        int last = -1;
        while(n > 0){
            last = n % 10;
            if(last == x)ok = true;
            n /= 10;
        }
        return (last != x && ok);
    }
};