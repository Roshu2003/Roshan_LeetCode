class Solution {
public:
    int countPoints(string s) {
        vector<vector<int>> cnt(10,vector<int>(3,0));
        int ans = 0;
        int n = s.size();
        for(auto i = 0; i < n; i += 2){
            char c = s[i];
            int rode = s[i + 1] - '0';
            int idx = -1;
            if(c == 'R')idx = 0;
            else if(c == 'G') idx = 1;
            else if(c == 'B')idx = 2;
            cnt[rode][idx] = 1;
        }
        for(int i = 0; i < 10; i++){
            if(cnt[i][0] == 1 && cnt[i][1] == 1 && cnt[i][2] == 1)ans++;
        }
        return ans;
    }
};