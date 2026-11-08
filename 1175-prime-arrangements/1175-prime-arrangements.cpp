class Solution {
public:
    int countPrime(int n){
        vector<int> prime(n + 1,1);
        prime[0] = false;
        if(n > 1)prime[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(!prime[i])continue;
            for(int j = i * i; j <= n; j += i){
                prime[j] = false;
            }
        }
        int ans = 0;
        for(int i = 2; i <= n; i++){
            if(prime[i])ans++;
        }
        return ans;
    }
    int numPrimeArrangements(int n) {
        int x = n;
        n = countPrime(n);
        int m = x - n;
        int mod = 1e9 + 7;
        long long ans = 1;
        for(int i = 2; i <= n; i++){
            ans = (ans * 1LL * i) % mod;
        }
        for(int i = 2; i <= m; i++){
            ans = (ans * 1LL * i) % mod;
        }
        return ans % mod;
    }
};