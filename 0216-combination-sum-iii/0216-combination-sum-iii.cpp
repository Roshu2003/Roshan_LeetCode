class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    void solve(int i,int sum,vector<int> &ds,int k){
        if(sum < 0)return;
        if(sum == 0){
            if(ds.size() == k)
            ans.push_back(ds);
            return;
        }
        if(i >= 9){
            if(sum == 0 && ds.size() == k)ans.push_back(ds);
            return;
        }
        //take
        ds.push_back(v[i]);
        solve(i + 1,sum - v[i],ds,k);
        ds.pop_back();
        //nottake 
        solve(i + 1,sum,ds,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        solve(0,n,ds,k);
        return ans;
    }
};