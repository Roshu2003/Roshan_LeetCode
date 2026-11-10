class Solution {
public:
    int getLucky(string s, int k) {
        string ans = "";
        for(auto it : s){
            int x = it - 'a';
            x++;
            ans += to_string(x);
        }
        while(k--){
            long long sum = 0;
            cout<<ans<<endl;
            for(auto it : ans) sum += (it - '0');
            ans = to_string(sum);
        }
        return stoi(ans);
    }
};