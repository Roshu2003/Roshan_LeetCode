class Solution {
public:
    long long modMul(long long a,long long b,int mod){
        long long ans = 1;
        while(b > 0){
            if(b % 2 == 1){
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        int ans = 0;
        int mod = 1e9 + 7;
        for(long long it : nums){
            int w = it % 10;
            long long d = it / 10;
            string s = to_string(d);
            long long x = stoll(s.substr(0,w));
            long long y = stoll(s.substr(w));
            ans = (ans + modMul(x,y,mod)) %  mod;
        }
        return ans % mod;
    }
};