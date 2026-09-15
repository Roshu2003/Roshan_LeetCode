class Solution {
public:
    string s;
    int k;
    int n;
    bool isPalindrom(int i, int j){
        int l = i;
        int r = j;
        while(l <= r){
            if(s[l] != s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    int dp[2001][2001];
    int solve(int i,int j){
        if(i >= n || j>= n)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(isPalindrom(i,j)){
            int take = 1 + solve(j + 1,j + k);
            int grow = solve(i,j + 1);
            int slide = solve(i + 1, j + 1);
            return dp[i][j] = max({take,grow,slide});
        }
            int grow = solve(i,j + 1);
            int slide = solve(i + 1, j + 1);
            return dp[i][j] = max(grow,slide);
        
    }
    int maxPalindromes(string s_, int k_) { 
        s = s_;
        k = k_;
        n = s.size();
        if(k == 1)return n;
        memset(dp,-1,sizeof(dp));
        return solve(0,k - 1);
    }
};