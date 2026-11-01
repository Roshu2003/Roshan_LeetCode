class Solution {
public:
    int findFist(int n){
        for(int i = 2; 1LL * i * i <= n; i++){
            if(n % i == 0)return i;
        }
        return n;
    }
    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1)return -1;
        int x = findFist(value);
        int l = value - x;
        if(l < 2 * index)return -1;
        int right_len = n - index - 1;
        if(right_len == 0)return value;
        long long ans = value + x + (right_len - 1) * 2LL;
        return ans;
    }
};
/*
  ? 3
  4 6 8 10
    5 10 15 20 25 30 35 ? ? ?
  left_len = 7  right-len = 3
  x = 5 // value / firstDiv > len - 1;
  5 * (15) = 75 
    35 / 5 = 7 (7 - 1) <
    5 * 6
    35 ->  30 25 

    39 / 13  = 3
*/ 