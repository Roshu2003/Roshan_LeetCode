class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        map<int,int> mp;
        for(auto it : words){
            int msk = 0;
            for(auto c : it){
                msk |= (1 << (c - 'a'));
            }
            ans += mp[msk];
            mp[msk]++;
        }
        return ans;
    }
};