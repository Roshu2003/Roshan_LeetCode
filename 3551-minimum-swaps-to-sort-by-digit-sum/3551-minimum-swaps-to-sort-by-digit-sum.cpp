class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i = 0; i < nums.size(); i++){
            int sum = 0;
            int x = nums[i];
            while(x > 0){
                sum += x  % 10;
                x /= 10;
            }
            v.push_back({sum,i});
        }
        sort(v.begin(),v.end(),[&](auto a, auto b){
            if(a.first != b.first)return a.first < b.first;
            int x = nums[a.second];
            int y = nums[b.second];
            return x < y;
        });
        int ans = 0;
        int n = nums.size();
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++){
            // if(v[i].second != i)ans++;
            if(vis[i] || v[i].second == i)continue;

            int j = i;
            int x = 0;
            while(!vis[j]){
                vis[j] = true;
                j = v[j].second;
                x++;
            }
            if(x > 1)ans += x - 1;
        }

        // ans = (ans / 2 + ans % 2);
        return ans;
    }
};