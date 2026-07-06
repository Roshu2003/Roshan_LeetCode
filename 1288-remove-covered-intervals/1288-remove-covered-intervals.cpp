class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        int n  = nums.size();
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(vis[j] || i == j)continue;
                if(nums[i][0] <= nums[j][0] && nums[i][1] >= nums[j][1]){
                    vis[j] = 1;
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
        int cnt = count(vis.begin(),end(vis),0);
        return cnt;
    }
};