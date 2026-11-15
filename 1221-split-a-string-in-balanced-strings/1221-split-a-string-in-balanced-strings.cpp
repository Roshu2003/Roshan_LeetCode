class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int cnt = 0;
        for(auto it : s){
            if(it == 'L')cnt++;
            else cnt--;
            ans += (cnt == 0);
        }
        return ans;
    }
};