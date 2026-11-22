class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> num(n);
        for(int i = 0; i < n; i++){
            num[i] = abs(s[i] - t[i]);
        }
        int ans = 0;
        int sum = 0;
        int st = 0;
        for(int i = 0; i < n; i++){
            sum += num[i];
            while(sum > maxCost){
                sum -= num[st];
                st++;
            } 
            ans = max(ans,i - st + 1);
        }
        return ans;
    }
};