class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // s = "1" + s + "1";
        int n = s.size();
        int one = 0;
        int cnt = 0;
        vector<int> a;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                one++;
                if(cnt != 0){
                    a.push_back(cnt);
                    cnt = 0;
                }
            }
            if(s[i] == '0'){
                cnt++;
            }
        }
        if(cnt != 0){
            a.push_back(cnt);
        }
        if(a.size() == 0){
            return one;
        }
        int sum = 0;
        for(int i = 0; i < a.size() - 1; i++){
            sum = max(sum,a[i] + a[i + 1]);
        }
        return sum + one;
    }
};