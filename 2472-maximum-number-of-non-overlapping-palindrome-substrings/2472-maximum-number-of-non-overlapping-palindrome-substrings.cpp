class Solution {
public:
    string s;
    int k;
    int n;
    vector<vector<int>> isPalindrom;
    // bool isPalindrom(int i, int j){
    //     int l = i;
    //     int r = j;
    //     while(l <= r){
    //         if(s[l] != s[r])return false;
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }
    int dp[2001][2001];
    int solve(int i,int j){
        if(i >= n || j >= n)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(isPalindrom[i][j]){
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
        isPalindrom.assign(n + 1,vector<int>(n + 1,0));
        //to get all the palindrom substrng
        for(int l = 1; l <= n; l++){
            for(int i = 0; i + l <= n; i++){
                int j = i + l  - 1;
                //one length;
                if(i == j){
                    isPalindrom[i][j] = 1;
                }
                else if(i + 1 == j){
                    isPalindrom[i][j] = (s[i] == s[j]);
                }
                else{
                    isPalindrom[i][j] = (isPalindrom[i + 1][j - 1] && s[i] == s[j]);
                }
            }
        }
        // memset(dp,-1,sizeof(dp));
        // return solve(0,k - 1);
        int ans = 0;
        for(int i  = 0; i + k <= n; i++){
            if(isPalindrom[i][i + k - 1]){
                ans++;
                i += k - 1;
            }
            else if(i + k < n && isPalindrom[i][i + k]){
                ans++;
                i += k;
            }
        }
        return ans;
    }
};