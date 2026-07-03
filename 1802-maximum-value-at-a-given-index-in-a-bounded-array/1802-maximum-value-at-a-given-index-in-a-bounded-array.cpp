class Solution {
public:
    long long calc(long long peak, long long len) {
        if (len < peak) {
            // full decreasing part: peak, peak-1 ... peak-len+1
            return (peak + (peak - len + 1)) * len / 2;
        } else {
            // decreasing till 1, then remaining are 1s
            long long ones = len - peak;
            return (peak + 1) * peak / 2 + ones;
        }
    }

    int maxValue(int n, int index, int maxSum) {
        long long lo = 1, hi = maxSum, ans = 1;

        auto check = [&](long long mid) -> bool {
            long long left = calc(mid - 1, index);
            long long right = calc(mid - 1, n - index - 1);
            long long total = left + right + mid;
            return total <= maxSum;
        };

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return (int)ans;
    }
};