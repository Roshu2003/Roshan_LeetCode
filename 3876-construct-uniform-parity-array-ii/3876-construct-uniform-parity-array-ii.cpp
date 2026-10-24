class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mn = INT_MAX;
        for(auto it : nums)mn = min(mn,it);
        // cout<<mn<<endl;
        if(mn % 2 == 0){
            for(auto it : nums){
                if(it % 2 == 1)return false;
            }
        }
        return true;
    }
};