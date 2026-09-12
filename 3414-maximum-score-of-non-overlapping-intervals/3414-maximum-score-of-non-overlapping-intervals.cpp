class Solution {
public:
    struct Result {
        long long score;
        vector<int> ind;
    };

    vector<vector<int>> nums;
    vector<int> nextInd;
    vector<vector<Result>> dp;
    vector<vector<bool>> vis;

    Result best(Result a, Result b) {
        if (a.score != b.score) {
            return (a.score > b.score) ? a : b;
        }

        if (a.ind < b.ind) {
            return a;
        }

        return b;
    }

    Result solve(int i, int k) {
        if (k == 4 || i >= nums.size())
            return {0, {}};

        if(vis[i][k]){
            return dp[i][k];
        }
        vis[i][k] = true;

        Result skip = solve(i + 1, k);
        Result takeNext = solve(nextInd[i], k + 1);

        Result take;
        take.score = nums[i][2] + takeNext.score;
        take.ind = takeNext.ind;
        take.ind.push_back(nums[i][3]);

        sort(take.ind.begin(), take.ind.end());

        return dp[i][k] = best(skip, take);
    }
    vector<int> maximumWeight(vector<vector<int>>& v) {
        for (auto i = 0; i < v.size(); i++) {
            nums.push_back({v[i][0], v[i][1], v[i][2], i});
        }
        sort(nums.begin(), nums.end(), [](auto& a, auto& b) {
            if (a[0] != b[0])
                return a[0] < b[0];

            return a[1] < b[1];
        });
        int n = v.size();
                //Find the next index
                nextInd.resize(n);

        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n;

            int target = nums[i][1] + 1;

            while (left < right) {

                int mid = left + (right - left) / 2;

                if (nums[mid][0] >= target) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            nextInd[i] = left;
        }
        dp.assign(
            n,
            vector<Result>(5)
        );
        vis.assign(n,vector<bool>(5,false));
        return solve(0, 0).ind;
    }
};