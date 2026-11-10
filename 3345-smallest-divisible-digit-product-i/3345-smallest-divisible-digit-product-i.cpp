class Solution {
public:
    int find(int n){
        int ans = 1;
        while(n > 0){
            ans *= (n % 10);
            n /= 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while(true){
            int x = find(n);
            if(x % t == 0)return n;
            n++;
        }
        return -1;
    }
};