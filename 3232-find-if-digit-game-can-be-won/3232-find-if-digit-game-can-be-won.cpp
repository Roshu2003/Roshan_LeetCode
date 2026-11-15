class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single = 0;
        int doubl = 0;
        for(auto it : nums){
            if(it < 10)single += it;
            else doubl += it;
        }
        return !(single == doubl);
    }
};