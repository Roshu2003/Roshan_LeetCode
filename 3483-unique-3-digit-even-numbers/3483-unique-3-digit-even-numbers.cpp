class Solution {
public:
    int totalNumbers(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums)mp[it]++;

        int ans = 0;
        int n = 10;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k <= 8; k+=2){
                    map<int,int>mp1;
                    mp1[i]++;
                    mp1[j]++;
                    mp1[k]++;
                    bool ok = true;
                    for(int u = 0; u < n; u++){
                        if(mp1[u] > mp[u]){
                            ok = false;
                            break;
                        }
                    }
                    ans += ok;
                }
            }
        }
        return ans;
    }
};