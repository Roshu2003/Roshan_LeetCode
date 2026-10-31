class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for(auto it : nums) x ^= it;
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int xBit = (x >> i) & 1;
            // cout<<xBit<<endl;
            int kBit = (k >> i) & 1;
            if(kBit != xBit)ans++;
        }
        return ans;
    }
};