class Solution {
public:
    int solve(int bit,int n){
        while((1 << bit) < n + 1){
            bit++;
        }
        return (1 << bit);
    }
    int uniqueXorTriplets(vector<int>& nums) {
        int  n = nums.size();
        if(n <= 2)return n;
        // return 1 << bit;
        return solve(0,n);
    }
};