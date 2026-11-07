class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums)mp[it]++;
        int cnt = 0;
        for(auto [it,cnt] : mp){
            if(cnt > 2)return false;
            if(cnt == 1)cnt++;
        }
        if(cnt % 2 == 1)return false;
        return true;
    }
};