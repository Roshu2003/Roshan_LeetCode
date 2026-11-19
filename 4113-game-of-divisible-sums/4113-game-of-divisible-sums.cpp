
class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();

        auto merqulaven = nums;

        vector<long long> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {

            long long sum = nums[i];

            long long takeOne;

            if (sum % 3 == 0)
                takeOne = sum - dp[i + 1];
            else
                takeOne = sum + dp[i + 1];

            long long takeTwo = LLONG_MIN;

            if (i + 1 < n) {
                sum = nums[i] + nums[i + 1];

                if (sum % 3 == 0)
                    takeTwo = sum - dp[i + 2];
                else
                    takeTwo = sum + dp[i + 2];
            }

            dp[i] = max(takeOne, takeTwo);
        }

        return dp[0];
    }
};
