class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        int digits = to_string(nums[0]).size();

        for (int i = 0; i < digits; i++) {
            vector<int> freq(10, 0);

            for (int x : nums) {
                int d = (x / (int)pow(10, i)) % 10;
                freq[d]++;
            }

            for (int j = 0; j < 10; j++) {
                ans += 1LL * freq[j] * (n - freq[j]);
            }
        }

        return ans / 2;
    }
};