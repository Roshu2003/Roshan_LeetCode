class Solution {
public:
    vector<int> cnt;
    void Count(int n){
        while(n > 0){
            cnt[n % 10]++;
            n /= 10;
        }
    }
    bool isFascinating(int n) {
        cnt.assign(10,0);
        Count(n);
        Count(n * 2);
        Count(3 * n);
        for(int i = 0; i < 10; i++){
            if(i == 0 && cnt[i] !=  0)return false;
            if(i != 0)
                if(cnt[i] != 1)return false;
        }
        return true;
    }
};