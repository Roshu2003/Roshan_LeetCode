class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        int k = n / 2;

        long long total = 0;

        for (int x : nums) {
            total += x;
        }

        long long windowSum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int ans = 0;

        // Check all n rotations
        for (int start = 0; start < n; start++) {

            if (windowSum > total - windowSum) {
                ans++;
            }

            // Remove current first element
            windowSum -= nums[start];

            // Add next element cyclically
            windowSum += nums[(start + k) % n];
        }

        return ans;
    }
};