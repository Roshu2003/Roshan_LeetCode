class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> ncr;
    long long solve(vector<int> nums){
        int n = nums.size();
        if(n < 3)return 1;
        int root = nums[0];
        vector<int> left;
        vector<int> right;
        for(int i = 1; i < n; i++){
            if(nums[i] < root)left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        long long l = solve(left) % mod;
        long long r = solve(right) % mod;
        long long z = ncr[n - 1][left.size()];
        return (1LL * ((l * r) % mod) *  z) % mod;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        ncr.assign(n + 1,vector<int>(n + 1,1));
        for(int i = 2; i < n; i++){// pascle traingle 
            for(int j = 1; j < i; j++){
                ncr[i][j] =( ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
            }
        }
        long long ans = solve(nums) % mod;
        return ans - 1;
    }
};