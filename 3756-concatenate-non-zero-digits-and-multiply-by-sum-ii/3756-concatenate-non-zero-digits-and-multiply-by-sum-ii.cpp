class Solution {
public:
    long long modpow(long long a,long long b,int mod){
        long long ans = 1;
        while(b > 0){
            if(b % 2)ans = (ans * a)%mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int mod = 1e9 + 7;
        vector<int> ans;
        int n = s.size();
        vector<int> k(n, 0);
        vector<long long> num(n, 0);
        vector<long long> pre(n, 0);
        long long x = 0;
        int cnt = 0;
        int sum = 0;
        for (auto i = 0; i < n; i++) {
            if (s[i] != '0') {
                cnt = (cnt + 1) % mod;;
                x = (x * 10 + (s[i] - '0')) % mod;
                sum = (sum +  (s[i] - '0')) % mod;
            }
            k[i] = cnt;
            num[i] = x;
            pre[i] = sum;
        }
        // for(auto it : pre)cout<<it<<" ";
        for (auto it : q) {
            int l = it[0];
            int r = it[1];
            long long  sum = pre[r] - (l - 1 >= 0 ? pre[l - 1] : 0);
            int kk = k[r] - (l - 1 >= 0 ? k[l - 1] : 0);
            // cout<<"Num"<<" "<<num[r]<<" "<<num[l]<<endl;
            long long x =( num[r] - (l - 1 >= 0 ? num[l - 1] * 1LL * modpow(10,kk,mod) % mod : 0)) % mod;
            // cout << sum << " " << x << endl;
            long long y = sum * 1LL * x % mod;
            if(y < 0)y += mod;
            ans.push_back(y);
        }
        return ans;
    }
};