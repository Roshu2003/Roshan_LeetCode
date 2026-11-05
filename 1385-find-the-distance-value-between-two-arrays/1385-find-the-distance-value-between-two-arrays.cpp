class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans = 0;;
        int n = arr1.size();
        for(int i = 0; i < n ;i++){
            auto l = lower_bound(arr2.begin(),arr2.end(),arr1[i] - d);
            auto r = upper_bound(arr2.begin(),arr2.end(),arr1[i] + d);
            if(l == r)ans++;
        }
        return ans;
    }
};