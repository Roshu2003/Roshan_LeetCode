
class Solution {
    using ll = long long;

    struct Node {
        ll sum = 0;
        ll sqSum = 0;
        ll lazy = 0;
    };

    vector<Node> seg;
    int n;

    void apply(int node, int l, int r, ll val) {
        ll len = r - l + 1;

        seg[node].sqSum += 2LL * val * seg[node].sum + val * val * len;

        seg[node].sum += val * len;
        seg[node].lazy += val;
    }

    void push(int node, int l, int r) {
        if (seg[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        ll val = seg[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        seg[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr, ll val) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        seg[node].sum = seg[node * 2].sum + seg[node * 2 + 1].sum;

        seg[node].sqSum = seg[node * 2].sqSum + seg[node * 2 + 1].sqSum;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n + 5, Node());

        unordered_map<int, int> last;
        ll ans = 0;

        for (int r = 0; r < n; r++) {
            int p = -1;

            if (last.count(nums[r])) {
                p = last[nums[r]];
            }

            update(1, 0, n - 1, p + 1, r, 1);

            last[nums[r]] = r;

            ans += seg[1].sqSum;
        }

        return static_cast<int>(ans);
    }
};
