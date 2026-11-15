class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for(auto it : nums){
            if(it == 1){
                if(cnt % 2 == 1)cnt++;
            }
            else{
                if(cnt % 2 == 0)cnt++;
            }
        }
        return cnt;
    }
};