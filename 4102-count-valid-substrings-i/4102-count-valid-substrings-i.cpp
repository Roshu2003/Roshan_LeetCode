class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int n = s.size();
        int st = -1;
        // for(int i = 0; i < n; i++){
        //     if(i - 2 >= 0 && s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c'){
        //         int len = i - st;
        //         ans += len * 1LL * (len + 1) / 2 - 1;
        //         st = i - 1;
        //     }
        // }
        // // cout<<ans<<endl;
        // long long len = n - st;
        // // cout<<len<<endl;
        // ans += 1LL * (len * 1LL * (len + 1) / 2);
        for(int i = 0;i  < n; i++){
            if(i >= 2 && s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c') st = i - 2;
            ans += i - st;
        }
        return ans;
    }
};