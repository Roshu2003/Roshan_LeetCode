class Solution {
public:
    int find(vector<vector<int>>& v, int x) {
        int n = v.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid][0] >= x) {
                ans = v[mid][1];
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& a,vector<vector<int>>& b) {
        vector<vector<int>> ans;
        // int n = a.size(); // approch - 1
        // int m = b.size();
        // int i = 0, j =0;
        // while (i < n && j < m) {
        //     if (a[i][0] < b[j][0]) {
        //         int x = find(a, a[i][0]);
        //         int y = find(b, a[i][0]);
        //         ans.push_back({a[i][0], x + y});
        //         i++;
        //     } else if(a[i][0] > b[j][0]) {
        //         int x = find(b, b[j][0]);
        //         int y = find(a, b[j][0]);
        //         ans.push_back({b[j][0], x + y});
        //         j++;
        //     }
        //     else{
        //         int x = find(b, b[j][0]);
        //         int y = find(a, b[j][0]);
        //         ans.push_back({b[j][0], x + y});
        //         j++;
        //         i++;
        //     }
        // }
        // while (i < n) {
        //     int x = find(a, a[i][0]);
        //     int y = find(b, a[i][0]);
        //     ans.push_back({a[i][0], x + y});
        //     i++;
        // }
        // while (j < m) {
        //     int x = find(b, b[j][0]);
        //       int y = find(a, b[j][0]);
        //     ans.push_back({b[j][0], x + y});
        //     j++;
        // }
        // return ans;

        // Approch - 2
        int n = a.size();
        int m = b.size();
         int v1 = 0, v2 = 0;
        vector<vector<int>> result;
        while (!a.empty() || !b.empty()) {
            int t = max(a.empty() ? INT_MIN : a.back()[0], b.empty() ? INT_MIN : b.back()[0]);
            if (!a.empty() && a.back()[0] == t) { v1 = a.back()[1]; a.pop_back(); }
            if (!b.empty() && b.back()[0] == t) { v2 = b.back()[1]; b.pop_back(); }
            result.push_back({t, v1 + v2});
        }
        ranges::reverse(result);
        return result;
    }
};