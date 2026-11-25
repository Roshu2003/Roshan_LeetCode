class Solution {
public:
    bool check(vector<int>v,int k) {
        int n = v.size();
        long long m1 = 1e9 + 7, b1 = 131;
        long long m2 = 1e9 + 9, b2 = 137;
        long long p1 = 1, p2 = 1;
        for (int i = 0; i < k; i++) {
            p1 = p1 * b1 % m1;
            p2 = p2 * b2 % m2;
        }
        long long h1 = 0, h2 = 0;
        for (int i = 0; i < k; i++) {
            h1 = (h1 * b1 + v[i]) % m1;
            h2 = (h2 * b2 + v[i]) % m2;
        }
        auto key = [&]() { return h1 * (long long)(1e9 + 9) + h2; };
        map<long long, int> mp;
        mp[key()]++;

        for (int i = k; i < n; i++) {
            h1 =
                (h1 * b1 % m1 - (long long)v[i - k] * p1 % m1 + v[i] + m1) % m1;
            h2 =
                (h2 * b2 % m2 - (long long)v[i - k] * p2 % m2 + v[i] + m2) % m2;
            mp[key()]++;
        }
        for (auto it : mp) {
            if (it.second == 1)
                return 1;
        }
        return 0;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = n;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(nums, mid)) {
                r = mid - 1;
                ans = mid;
            } else
                l = mid + 1;
        }
        return ans;
    }
};