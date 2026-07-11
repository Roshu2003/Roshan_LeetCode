class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int n = nums.size();

        map<int,int> even, odd;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                even[nums[i]]++;
            else
                odd[nums[i]]++;
        }

        vector<pair<int,int>> e,o;

        for(auto &[x,c] : even)
            e.push_back({c,x});

        for(auto &[x,c] : odd)
            o.push_back({c,x});

        sort(e.rbegin(), e.rend());
        sort(o.rbegin(), o.rend());

        // add dummy value for second maximum
        e.push_back({0,-1});
        o.push_back({0,-1});

        int evenSize = (n+1)/2;
        int oddSize = n/2;

        int ans = INT_MAX;

        // choose top even, second best odd
        if(e[0].second != o[0].second)
            ans = min(ans, 
                evenSize - e[0].first + oddSize - o[0].first);

        else {
            // replace odd choice
            ans = min(ans,
                evenSize - e[0].first + oddSize - o[1].first);

            // replace even choice
            ans = min(ans,
                evenSize - e[1].first + oddSize - o[0].first);
        }

        return ans;
    }
};