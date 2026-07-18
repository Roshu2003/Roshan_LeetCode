class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = -1;
        int b = 10001;
        for(auto it : nums){
            a=  max(a,it);
            b = min(b,it);
        }
        return gcd(a,b);
    }
};